#pragma once

#include<cassert>
#include<vector>

#include "board.hpp"

namespace connect {
	namespace solver {

		constexpr int BIT_SIZE = 56;

		class TranspositionTable {
		public: 
			struct Entry {
				BitBoard key : BIT_SIZE;
				int8_t value;
			};

			TranspositionTable(unsigned int size)
				: cache_(size)
			{
			}

			int8_t get(BitBoard key) {
				assert(key < (1LL << BIT_SIZE));
				size_t i = index(key);
				const Entry& entry = cache_[i];
				if (entry.key == key)
					return entry.value;

				return INT8_MIN;
			}

			void put(BitBoard key, int8_t val) {
				assert(key < (1LL << BIT_SIZE));
				size_t i = index(key);
				cache_[i].key = key;
				cache_[i].value = val;
			}

			size_t index(BitBoard key) {
				return key % cache_.size();
			}

		private:
			std::vector< Entry> cache_;

		};
	}
}