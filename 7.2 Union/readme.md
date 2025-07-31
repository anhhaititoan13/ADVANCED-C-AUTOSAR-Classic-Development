# Union

## Giới thiệu
- `union` để chia sẻ vùng nhớ giữa các thành viên khác nhau.

### Mục đích:
- Chia sẻ cùng một vùng nhớ giữa các thành viên khác kiểu.
- Giúp tiết kiệm bộ nhớ.

### Cú pháp:
```c
union Data {
    uint8_t a;
    uint16_t b;
    uint32_t c;
};
```

### Lưu ý:
- Tại một thời điểm chỉ sử dụng một thành viên.
- Kích thước `union` bằng kích thước thành viên lớn nhất.

---

## Ứng dụng nâng cao với Union

### Mô hình truyền dữ liệu:
```c
typedef union {
    struct {
        uint8_t id[2];
        uint8_t data[4];
        uint8_t check_sum[2];
    } data;
    uint8_t frame[8];
} Data_Frame;
```

Dùng `strcpy()` để sao chép từ MCU A sang MCU B thông qua `frame[]`.

---

## Ứng dụng Struct & Union trong Embedded

- Cấu hình ngoại vi: GPIO, UART, SPI...
- Truyền dữ liệu giữa các module MCU.
- Giao tiếp CAN, I2C, UART nhúng frame header/payload/checksum.

---

## Tổng kết

| Đặc điểm     | Struct                              | Union                               |
|--------------|-------------------------------------|--------------------------------------|
| Kích thước   | Tổng kích thước các thành viên      | Kích thước thành viên lớn nhất       |
| Bộ nhớ       | Mỗi thành viên có vùng nhớ riêng     | Các thành viên dùng chung vùng nhớ   |
| Ứng dụng     | Dữ liệu đa chiều                    | Tiết kiệm bộ nhớ                     |

---

## Ghi nhớ

- Dùng `struct` khi cần lưu trữ nhiều dữ liệu cùng lúc.
- Dùng `union` khi chỉ cần một giá trị tại một thời điểm.
- `bit field` hữu ích khi tối ưu kích thước trong hệ thống nhúng.

