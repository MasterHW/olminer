#pragma once

#include "blake2.h"

#include <libdevcore/Common.h>
#include <libdevcore/FixedHash.h>
#include <ethash/ethash.hpp>

namespace dev {
namespace ol {

  struct olhash_result {
    uint64_t distance;
  };
  
  struct search_result {
    bool solution_found = false;
    uint64_t nonce = 0;
    uint64_t distance = 0;

    search_result() noexcept = default;

    search_result(olhash_result res, uint64_t n) noexcept
      : solution_found(true), nonce(n), distance(res.distance)
    {}
  };
  
  h256 blake2bl_from_bytes(const bytes& data);

  uint64_t distance(const bytes&, const bytes&);
  
  search_result search(const bytes& work,
                       const bytes& miner_key,
                       const bytes& merkle_root,
                       uint64_t difficulty,
                       uint64_t nonce,
                       size_t iterations);
}
}
