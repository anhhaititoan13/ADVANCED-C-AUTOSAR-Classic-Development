
# Storage Class

## 1. Extern
Khái niệm:
- Từ khóa extern dùng để khai báo rằng một biến/hàm được định nghĩa ở một file khác.
- Dùng để truy cập biến/hàm giữ liên kết giữa các file
### Demo

```c
// File test.c
#include <stdio.h>
int var_global = 50; // 0x01
void display() {
    printf("%d\n", var_global);
}

// File main.c
#include <stdio.h>
extern int var_global;
extern void display();
int main() {
    display();
    return 0;
}
```
## 2. Static Local
Khái niệm:
- Biến static cục bộ giữ giá trị qua các lần gọi hàm.
- Phạm vi truy cập trong hàm
### Demo

```c
// File test.c
#include <stdio.h>
int var_global = 50; // 0x01
void display() {
    printf("%d\n", var_global);
}

// File main.c
#include <stdio.h>
extern int var_global;
extern void display();
int main() {
    display();
    return 0;
}
```
### Demo

```c
#include <stdio.h>
void exampleFunction() {
    static int count = 0;
    count++;
    printf("Count: %d\n", count);
}
int main() {
    exampleFunction(); // Count: 1
    exampleFunction(); // Count: 2
    exampleFunction(); // Count: 3
    return 0;
}
```
## 3. Static Global

Khái niệm:
- Biến/hàm static toàn cục có phạm vi trong file nguồn.
- Dùng khi thiết kế thư viện
### Demo

```c
// File motor.h
#ifndef MOTOR_H
#define MOTOR_H

typedef struct {
    void (*start)(int gpio);
    void (*stop)(int gpio);
    void (*changeSpeed)(int gpio, int speed);
} MotorController;

typedef int PIN;

static void startMotor(PIN pin);
static void stopMotor(PIN pin);
static void changeSpeedMotor(PIN pin, int speed);

void init_motor(MotorController *motorName);
#endif
```
## 4. Static trong Class (C++)
Khái niệm:
- static member thuộc về class, không phải các đối tượng cụ thể của class đó.
- Các đối tượng của class sẽ chia sẻ cùng một bản sao duy nhất
### Demo

```c
// File motor.h
#ifndef MOTOR_H
#define MOTOR_H

typedef struct {
    void (*start)(int gpio);
    void (*stop)(int gpio);
    void (*changeSpeed)(int gpio, int speed);
} MotorController;

typedef int PIN;

static void startMotor(PIN pin);
static void stopMotor(PIN pin);
static void changeSpeedMotor(PIN pin, int speed);

void init_motor(MotorController *motorName);
#endif
```
### Demo

```c
class PEN {
public:
    static int pen_length;
    PEN();
    void set_length(int length) { pen_length = length; }
};
int PEN::pen_length = 0;
```
## 5. Volatile
Khái niệm:
- volatile chỉ rõ biến có thể thay đổi ngoài tầm kiểm soát của chương trình.
- Ngăn complier tối ưu hóa biển, giữ cho các thao tác trên biến được thực hiện như đã được định nghĩa.
### Demo
```c
#include "stm32f10x.h"
volatile int i = 0;
int main() {
    while (1) {
        i = *((int *)0x20000000);
        if (i > 0) break;
    }
}
```
## 6. Register
Khái niệm:
- register gợi ý complier lưu biến trong thanh ghi CPU.
- Tăng tốc độ truy cập.
### Demo
```c
#include <stdio.h>
#include <time.h>
int main() {
    clock_t start_time = clock();
    register int i;
    for (i = 0; i < 2000000; ++i) {}
    clock_t end_time = clock();
    printf("Time: %f s\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);
    return 0;
}
```