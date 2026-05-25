#include "crop_img.h"
#include <assert.h>

void img_crop(uint8_t *src_image, uint8_t *dst_img, const uint32_t src_stride,
              const uint16_t dst_width, const uint16_t height,
              const uint16_t dst_bpp)
{
  const uint8_t *pIn = src_image;
  uint8_t *pOut = dst_img;
  const uint32_t dst_line_size = (dst_width * dst_bpp);

  /* Copy line per line */
  for (uint32_t i = 0; i < height; i++)
  {
    memcpy(pOut, pIn + (i * src_stride), dst_line_size);
    pOut += dst_line_size;
  }
}