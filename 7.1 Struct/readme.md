
# 4. Struct

Struct là một cấu trúc dữ liệu cho phép tự định nghĩa một kiểu dữ liệu mới bằng cách nhóm các biến có các kiểu dữ liệu khác lại với nhau
## Examples

```c
typedef struct Example {
    unit8_t a;     //1byte
    unit16_t b;    //2byte
    unit32_t c;    //4byte
} Example;

//Cách khai báo biến
Example ex1;
Example* ex2 = ex1;

int main(){
    ex1.a = 23;
    ex2->a = 25;
}
```

## Padding byte
Padding byte trong struct là các byte trống được trình biên dịch tự động chèn vào giữa (hoặc sau) các thành viên của struct để đảm bảo căn chỉnh bộ nhớ (memory alignment) theo yêu cầu của kiến trúc CPU.
## Examples

```c
struct Example {
    char  a;   // 1 byte | 3 byte padding
    int   b;   // 4 byte
    char  c;   // 1 byte 
    //(1 + 3 + 4 + 1 =9) => cần thêm 3 byte padding
    //tổng 12 byte
};
===============================================================
struct Example2{
    int b;     //4 byte
    char a;    //1 byte
    char c;    //1 byte
    //4 + 1 + 1 => cần thêm 2 byte padding
    //tổng 8 byte
}
```


## Bit Field

Cho phép sử dụng một số lượng bit cụ thể cho từng thành viên. Có thể chia bộ nhớ theo số bit cần thiết thay vì sử dụng toàn bộ kích thước của một kiểu dữ liệu.
```c
struct name_struct {    
    <data type 1> <member 1> : <number of bits>;
    <data type 2> <member 2> : <number of bits>;
```
Số bit chỉ định trực tiếp giới hạn phạm vi giá trị có thể lưu. Ví dụ: một bit field khai báo với : 3 có thể lưu các giá trị từ 0 đến 7 (đối với unsigned).
Ứng dụng: lưu cờ trạng thái, cấu hình bit trong thanh ghi.
## Examples

```c
typedef struct Example {
    unit8_t a;     //1byte
    unit16_t b;    //2byte
    unit32_t c;    //4byte
} Example;

//Cách khai báo biến
Example ex1;
Example* ex2 = ex1;

int main(){
    ex1.a = 23;
    ex2->a = 25;
}
```

## Bit Field Example

```c
struct Example {
    int8_t  a : 1;  // 1 bit
    int8_t  b : 4;  // 4 bit
};
// Kích thước struct: 1 byte
```
Ở đây a và b cùng là int8_t, nên cả hai gói chung trong 1 byte.
```c
struct Example {
    int8_t  a : 1;  // 1 bit
    int16_t b : 4;  // 4 bit
};
// Kích thước struct: 4 byte
```