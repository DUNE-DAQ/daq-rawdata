/**
 * @file TriggerPrimitivesFragment.hpp Fragment format for trigger primitives
 *
 * This is part of the DUNE DAQ, copyright 2020.
 * Licensing/copyright details are in the COPYING file that you should have
 * received with this code.
 */
#ifndef DATAFORMATS_INCLUDE_DATAFORMATS_TRIGGER_TRIGGERPRIMITIVESFRAGMENT_HPP_
#define DATAFORMATS_INCLUDE_DATAFORMATS_TRIGGER_TRIGGERPRIMITIVESFRAGMENT_HPP_

#include <cstddef> // For size_t
#include <cstdint>
#include <stdexcept>

namespace dunedaq {

namespace dataformats {

struct TriggerPrimitivesFragment
{
  static constexpr uint32_t s_tpf_header_magic = 0xcafecafe; // NOLINT(build/unsigned)
  static constexpr uint32_t s_tpf_version = 1;               // NOLINT(build/unsigned)

  struct TriggerPrimitive
  {
    uint64_t time_start;          // NOLINT(build/unsigned)
    uint64_t time_peak;           // NOLINT(build/unsigned)
    uint64_t time_over_threshold; // NOLINT(build/unsigned)
    uint32_t channel;             // NOLINT(build/unsigned)
    uint32_t adc_integral;        // NOLINT(build/unsigned)
    uint16_t adc_peak;            // NOLINT(build/unsigned)
    uint16_t detid;               // NOLINT(build/unsigned)
    uint32_t type;                // NOLINT(build/unsigned)
    uint32_t algorithm;           // NOLINT(build/unsigned)
    uint16_t version;             // NOLINT(build/unsigned)
    uint16_t flag;                // NOLINT(build/unsigned)
  };

  uint32_t magic = s_tpf_header_magic; // NOLINT(build/unsigned)
  uint32_t version = s_tpf_version;    // NOLINT(build/unsigned)
  uint64_t num_trigger_primitives;     // NOLINT(build/unsigned)

  const TriggerPrimitive& at(size_t i) const
  {
    if (i >= num_trigger_primitives) {
      throw std::out_of_range("Primitive index out of range");
    }
    const void* start_of_primitives = this + 1;
    return *reinterpret_cast<const TriggerPrimitive*>( // NOLINT
      static_cast<const char*>(start_of_primitives) + i * sizeof(TriggerPrimitive));
  }

  TriggerPrimitive& at(size_t i)
  {
    // According to https://stackoverflow.com/questions/123758/ this
    // is a sensible way to avoid duplicating the body of the const
    // and non-const versions of the function, recommended in
    // "Effective C++"
    return const_cast<TriggerPrimitive&>(static_cast<const TriggerPrimitivesFragment&>(*this).at(i));
  }
};

} // namespace dataformats
} // namespace dunedaq

#endif // DATAFORMATS_INCLUDE_DATAFORMATS_TRIGGER_TRIGGERPRIMITIVESFRAGMENT_HPP_
