#include <TFT_eSPI.h>
#include <TJpg_Decoder.h>

typedef struct _VideoInfo{
  const uint8_t* const* frames;
  const uint16_t* frames_size;
  uint16_t num_frames;
} VideoInfo;

#include "video01.h"
#include "video02.h"
#include "video03.h"
#include "video04.h"
#include "video05.h"
#include "video06.h"
#include "video07.h"
#include "video08.h"
#include "video09.h"
#include "video10.h"
#include "video11.h"
#include "video12.h"
#include "video13.h"
#include "video14.h"

TFT_eSPI tft = TFT_eSPI();

// Khai báo danh sách các video
VideoInfo* videoList[] = {
//  &video01,
//  &video02,
//  &video03,
//  &video04,
//  &video05,
//  &video06,
//  &video07,
//  &video08

  &video09,
  &video10,
  &video11,
  &video12,
  &video13,
  &video14
};
const uint8_t NUM_VIDEOS = sizeof(videoList) / sizeof(videoList[0]);

// Callback để TJpg_Decoder gọi khi vẽ block ảnh
bool tft_output(int16_t x, int16_t y, uint16_t w, uint16_t h, uint16_t* bitmap) {
  if (x >= tft.width() || y >= tft.height()) return false;
  tft.pushImage(x, y, w, h, bitmap);
  return true;
}

// Vẽ một frame của video cụ thể
void drawJPEGFrame(const VideoInfo* video, uint16_t frameIndex) {
  const uint8_t* jpg_data = (const uint8_t*)pgm_read_ptr(&video->frames[frameIndex]);
  uint16_t jpg_size = pgm_read_word(&video->frames_size[frameIndex]);

  if (!TJpgDec.drawJpg(0, 0, jpg_data, jpg_size)) {
    Serial.printf("❌ Decode failed on frame %d\n", frameIndex);
  }
}

void setup() {
  Serial.begin(115200);
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);

  // Cấu hình JPEG decoder
  TJpgDec.setJpgScale(1);
  TJpgDec.setSwapBytes(true);
  TJpgDec.setCallback(tft_output);
}

void loop() {
  for (uint8_t v = 0; v < NUM_VIDEOS; v++) {
    VideoInfo* currentVideo = videoList[v];
    for (uint16_t f = 0; f < currentVideo->num_frames; f++) {
      drawJPEGFrame(currentVideo, f);
      delay(20);  // thời gian giữa các frame
    }
    delay(300);  // Delay giữa các video
  }
}
