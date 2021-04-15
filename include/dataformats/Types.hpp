/**
 * @file Types.hpp  Types used in Data Structures
 *
 * This is part of the DUNE DAQ Application Framework, copyright 2020.
 * Licensing/copyright details are in the COPYING file that you should have
 * received with this code.
 */

#ifndef DATAFORMATS_INCLUDE_DATAFORMATS_TYPES_HPP_
#define DATAFORMATS_INCLUDE_DATAFORMATS_TYPES_HPP_

#include <cstdint>
#include <limits>

/**
 * @brief The DUNE-DAQ namespace
 */
namespace dunedaq {

/**
 * @brief Dataformats code
 */
namespace dataformats {

/**
 * @brief A std::exception class indicating that a malloc failed
 */
class MemoryAllocationFailed : public std::exception
{
public:
  MemoryAllocationFailed(std::string file, int line, size_t bytes)
    : m_file(file)
    , m_line(line)
    , m_bytes(bytes)
  {
    m_what = m_file + ":" + std::to_string(m_line) + ": Malloc of " + std::to_string(m_bytes) + " bytes failed";
  }

  const char* what() const noexcept override { return m_what.c_str(); }

  std::string get_file() const { return m_file; }
  int get_line() const { return m_line; }
  size_t get_bytes() const { return m_bytes; }

private:
  std::string m_file;
  int m_line;
  size_t m_bytes;
  std::string m_what;
};

/**
 * @brief Type used to represent run number
 */
using run_number_t = uint32_t; // NOLINT(build/unsigned)
/**
 * @brief Type used to represent trigger number
 */
using trigger_number_t = uint64_t; // NOLINT(build/unsigned)
/**
 * @brief Type used to represent Fragment type ID
 */
using fragment_type_t = uint32_t; // NOLINT(build/unsigned)
/**
 * @brief Type used to represent Fragment size
 */
using fragment_size_t = uint64_t; // NOLINT(build/unsigned)
/**
 * @brief Type used to represent DUNE timing system timestamps
 */
using timestamp_t = uint64_t;     // NOLINT(build/unsigned)
using timestamp_diff_t = int64_t; ///< Used to represent differences between timestamps
/**
 * @brief Type used to represent Trigger Decision trigger types
 */
using trigger_type_t = uint16_t; // NOLINT(build/unsigned)

/**
 * @brief Default values for dataformats types
 */
class TypeDefaults
{
public:
  static constexpr run_number_t s_invalid_run_number =
    std::numeric_limits<run_number_t>::max(); ///< An invalid run number
  static constexpr trigger_number_t s_invalid_trigger_number =
    std::numeric_limits<trigger_number_t>::max(); ///< An invalid trigger number
  static constexpr fragment_type_t s_invalid_fragment_type =
    std::numeric_limits<fragment_type_t>::max(); ///< An invalid fragment type
  static constexpr fragment_size_t s_invalid_fragment_size =
    0; ///< Invalid size for a Fragment (as FragmentHeader is counted as well)
  static constexpr timestamp_t s_invalid_timestamp = std::numeric_limits<timestamp_t>::max(); ///< An invalid timestamp
  static constexpr timestamp_diff_t s_invalid_timestamp_diff =
    std::numeric_limits<timestamp_diff_t>::max(); ///< An invalid timestamp difference

  static constexpr trigger_type_t s_invalid_trigger_type =
    std::numeric_limits<trigger_type_t>::max(); ///< An invalid trigger type
};

} // namespace dataformats
} // namespace dunedaq

#endif // DATAFORMATS_INCLUDE_DATAFORMATS_TYPES_HPP_