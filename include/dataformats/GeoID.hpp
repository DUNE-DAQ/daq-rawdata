/**
 * @file GeoID.hpp Geometric Identification for a link
 *
 * This is part of the DUNE DAQ Application Framework, copyright 2020.
 * Licensing/copyright details are in the COPYING file that you should have
 * received with this code.
 */

#ifndef DATAFORMATS_INCLUDE_DATAFORMATS_GEOID_HPP_
#define DATAFORMATS_INCLUDE_DATAFORMATS_GEOID_HPP_

#include <cstdint>
#include <ostream>
#include <tuple>

namespace dunedaq {
namespace dataformats {

/**
 * @brief Represents a coordinate point in the DAQ's logical coordinate system (i.e. not physical coordinates)
*/
struct GeoID
{
  /**
   * @brief APA Number of the component
  */
  uint32_t apa_number {0};  // NOLINT(build/unsigned)
  /**
   * @brief Link Number of the component
  */
  uint32_t link_number {0}; // NOLINT(build/unsigned)

  /**
   * @brief Comparison operator (to allow GeoID to be used in std::map)
   * @param other GeoID to compare
   * @return The result of std::tuple compare using apa_number and link_number
  */
  bool operator<(const GeoID& other) const
  {
    return std::tuple(apa_number, link_number) < std::tuple(other.apa_number, other.link_number);
  }

};

/**
 * @brief Stream a GeoID instance in a human-readable form
 * @param o Stream to output to
 * @param id GeoID to stream
 * @return Stream instance for further streaming
*/
inline std::ostream&
operator<<(std::ostream& o, GeoID const& id)
{
  return o << "APA: " << id.apa_number << ", link: " << id.link_number;
}
} // namespace dataformats
} // namespace dunedaq

#endif // DATAFORMATS_INCLUDE_DATAFORMATS_GEOID_HPP_
