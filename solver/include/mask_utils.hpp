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


			static constexpr BitBoard create_col_mask(col_t height, col_t width, col_t col_offset) {
				BitBoard mask(1);
				for (col_t i = 0; i < height * width; i += height + 1)
					mask |= mask << (height + 1);

				return 1;
			}

			template<col_t TWidth>
			static constexpr std::array<col_t, TWidth> create_order() {
				std::array<col_t, TWidth> order{};

				for (size_t i = 0; i < TWidth; i++)
				{
					if (i & 1)
						order[i] = (TWidth + i) / 2;
					else
						order[i] = (TWidth - i - 1) / 2;
				}

				return order;
			}
		};

		/*
		template<col_t THeight, col_t TWidth>
		class ColumnMasks {
		public:
			ColumnMasks() : column_masks_() {
				for (col_t i = 0; i < TWidth; ++i) {
					column_masks_[i] = MaskUtils::create_col_mask(1, 2, 3);
				}
			}

			Bitboard get(size_t index) const {
				return column_masks_[index];
			}

		private:
			std::array<Bitboard, TWidth> column_masks_;
		};
		*/

		template<col_t THeight, col_t TWidth>
		class Masks {

		public:
			inline constexpr BitBoard row(col_t index) const {
				return row_masks_[index];
			}

			inline constexpr BitBoard col(col_t index) const {
				return col_masks_[index];
			}

		private:
			static constexpr std::array<BitBoard, TWidth> GetRowMasks() {
				std::array<BitBoard, TWidth> masks{};
				for (col_t row_offset = 0; row_offset < THeight; ++row_offset)
					masks[row_offset] = MaskUtils::create_row_mask(THeight, TWidth, row_offset);
				return masks;
			}

			static constexpr std::array<BitBoard, TWidth> GetColMasks() {
				std::array<BitBoard, TWidth> masks{};
				for (col_t row_offset = 0; row_offset < THeight; ++row_offset)
					masks[row_offset] = MaskUtils::create_row_mask(THeight, TWidth, row_offset);
				return masks;
			}

			static constexpr std::array<BitBoard, TWidth> row_masks_ = GetRowMasks();
			static constexpr std::array<BitBoard, TWidth> col_masks_ = GetColMasks();
		};
	}
}