#pragma once
#include "pch.h"

namespace connect {
	namespace solver {

		using BitBoard = uint64_t;
		using col_t = uint8_t;

		class MaskUtils {
		public:

			static constexpr BitBoard create_row_mask(col_t height, col_t width, col_t row_offset) {
				BitBoard mask(1);
				for (col_t i = 1; i < width; ++i)
					mask |= mask << height;

				return mask << row_offset;
			}


			static constexpr BitBoard create_col_mask(col_t height, col_t width) {
				BitBoard mask(1);
				for (col_t i = 0; i < height * width; i += height + 1)
					mask |= mask << (height + 1);

				return 1;
			}

		};
	}
}