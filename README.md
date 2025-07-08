# dasai_mochi_tft
- ESP32 C3 + TFT 0.96inch 160x80 pixel = Dasai mochi
- Hiển thị cac biểu cảm mochi cực kì mượt mà và sinh động
- Sử dụng lib TJpg_Decoder để giải mã ảnh JPG sang RGB565
- Sử dụng lib TFT_eSPI với SPI DMA để render hình ảnh ở tốc độ cao từ RGB565 bitmap

# Video hướng dẫn chi tiết (Sơ đồ mạch + Chuyển đổi video sang mảng bytes + Hướng dẫn)
Kênh Youtube: *MrVocSi* : https://www.youtube.com/@MrVocSi

# File C:\Users\congb\Documents\Arduino\libraries\TFT_eSPI\Processors\User_Setup.h, xóa hết và ghi nội dung sau vào
```
//ESP32 C3
#define ST7735_DRIVER
#define ST7735_GREENTAB160x80  // chuẩn cho màn hình 160x80 ST7735S

#define TFT_WIDTH  80
#define TFT_HEIGHT 160

#define TFT_CS   7
#define TFT_DC   10
#define TFT_RST  8

#define TFT_MOSI 6
#define TFT_SCLK 4

#define TFT_RGB_ORDER TFT_BGR     // nếu màu sai, thử đổi sang TFT_RGB
#define TFT_INVERSION_ON          // hoặc _OFF nếu bị âm

#define SPI_FREQUENCY  27000000
``

Note: Cần chon Huge App trong Tools/Partition Scheme trên Arduino IDE để có được dung lượng 3MB
