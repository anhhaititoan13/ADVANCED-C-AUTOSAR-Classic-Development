
# Bài 1 Complier - Macros

## 1. Complier
Compiler là trình biên dịch chuyển mã nguồn (C/C++) thành mã máy.

Quy trình biên dịch:

- Preprocessor: Xử lý tiền biên dịch (#include, #define, macro).

- Compiler: Dịch sang Assembly (.s).

- Assembler: Dịch Assembly sang Object code (.o).

- Linker: Liên kết tất cả để tạo file thực thi (.exe).
## Demo
- Preprocessor:
```c
g++ -E file.cpp -o output.i
```
- Compiler:
```
g++ -S file.cpp -o output.s
g++ -S output.i -o output.s
```
- Assembler:
```
g++ -c file.cpp -o output.obj
g++ -c output.s -o output.obj
```
- Linker:
```
g++ my_program.o my_library.o -o my_program
g++ my_program.o -o my_program -L/path/to/library –lmylib
g++ *.cpp –o my_program (biên dịch và liên kết trong 1 lần ra file thực thi)
```
- Execute:
```
./my_program
```
## 2. Macro
Macro là tập lệnh tiền xử lý, thay thế văn bản trước khi biên dịch.

### 2.1 #define
Dùng để định nghĩa hằng hoặc macro hàm.
```c
#define PI 3.14

int main() {
    double r = 5.0;
    double area = PI * r * r;
    printf("Area: %.2f\n", area);
    return 0;
}
```
### 2.2 Macro hàm
```c
#define SQUARE(x) ((x) * (x))

int main() {
    int result = SQUARE(5);
    printf("Square of 5: %d\n", result);
    return 0;
}
```
### 2.3 Macro đa dòng
```c
#define DISPLAY_SUM(a, b)          \
    printf("Sum of %d and %d = %d\n", a, b, (a + b))
```
## 3. #undef
Hủy định nghĩa macro:
```c
#define A 10
#undef A
#define A 20
```
## 4. Biên dịch điều kiện
Cho phép biên dịch tùy theo macro.
```c
#if MCU == STM32
    // code cho STM32
#elif MCU == ESP32
    // code cho ESP32
#else
    // code cho MCU khác
#endif
```
Sử dụng #ifdef / #ifndef:
```c
#ifndef __ABC_H
#define __ABC_H
    int a = 10;
#endif
```
## 5. Toán tử trong Macro
- '#' (stringize): Chuyển tham số thành chuỗi.
```c
#define STRINGIZE(x) #x
printf("%s", STRINGIZE(Hello));
```
- '##' (token-pasting): Ghép 2 token.
```c
#define DECLARE_VAR(pre, num) int pre##num
DECLARE_VAR(var, 1); // int var1;
```
## 6. Variadic Macro
Macro cho phép sử dụng tham số biến động.
```c
#define PRINTF(...) printf(__VA_ARGS__)
```

## 