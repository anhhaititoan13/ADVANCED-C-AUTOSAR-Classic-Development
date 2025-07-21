# Bitmask trong lập trình C

Bitmask là một kỹ thuật sử dụng các bit để lưu trữ và thao tác với các cờ (flags) hoặc trạng thái.  
Kỹ thuật này giúp tối ưu bộ nhớ, thao tác nhanh và rõ ràng trong việc kiểm soát các trạng thái hoặc quyền truy cập.

---

## Các phép toán Bitwise

### `~` NOT bitwise
Đảo ngược tất cả các bit.
```c
int result = ~num;
```

### `&` AND bitwise
Bit tương ứng là 1 nếu cả hai bit đều là 1.
```c
int result = num1 & num2;
```

### `|` OR bitwise
Bit tương ứng là 1 nếu có ít nhất một bit là 1.
```c
int result = num1 | num2;
```

### `^` XOR bitwise
Bit tương ứng là 1 nếu chỉ một trong hai bit là 1.
```c
int result = num1 ^ num2;
```

### `<<` Shift left
Dịch các bit sang trái.
```c
int result = num << shiftAmount;
```

### `>>` Shift right
Dịch các bit sang phải.
```c
int result = num >> shiftAmount;
```

---

## Ví dụ 1: Quản lý lựa chọn bằng Bitmask

```c
#include <stdio.h>
#include <stdint.h>

#define GENDER   (1 << 0)
#define TSHIRT   (1 << 1)
#define HAT      (1 << 2)
#define SHOES    (1 << 3)

void enableFeature(uint8_t *features, uint8_t feature) {
    *features |= feature;
}

void disableFeature(uint8_t *features, uint8_t feature) {
    *features &= ~feature;
}

void listSelectedFeatures(uint8_t features) {
    if (features & GENDER)  printf("- Gender\n");
    if (features & TSHIRT)  printf("- T-Shirt\n");
    if (features & HAT)     printf("- Hat\n");
    if (features & SHOES)   printf("- Shoes\n");
}

int main() {
    uint8_t options = 0;

    enableFeature(&options, GENDER | TSHIRT | HAT);
    disableFeature(&options, TSHIRT);
    listSelectedFeatures(options);

    return 0;
}
```

---

## Ví dụ 2: Điều khiển LED bằng Bitmask

```c
#include <stdio.h>

#define LED1 (1 << 0)
#define LED2 (1 << 1)
#define LED3 (1 << 2)
#define LED4 (1 << 3)

void enableLED(unsigned int *port, unsigned int led) {
    *port |= led;
}

void disableLED(unsigned int *port, unsigned int led) {
    *port &= ~led;
}

int main() {
    unsigned int GPIO_PORT = 0;

    enableLED(&GPIO_PORT, LED1 | LED3);

    if (GPIO_PORT & LED1) printf("LED1 is ON\n");
    if (GPIO_PORT & LED3) printf("LED3 is ON\n");

    disableLED(&GPIO_PORT, LED1);
    enableLED(&GPIO_PORT, LED2);

    if (GPIO_PORT & LED1) printf("LED1 is ON\n");
    if (GPIO_PORT & LED2) printf("LED2 is ON\n");
    if (GPIO_PORT & LED3) printf("LED3 is ON\n");

    return 0;
}
```

---

## Ví dụ 3: Bitfield trong struct LED

```c
#include <stdio.h>
#include <stdint.h>

#define ENABLE  1

typedef struct {
    uint8_t LED1 : 1;
    uint8_t LED2 : 1;
    uint8_t LED3 : 1;
    uint8_t LED4 : 1;
    uint8_t LED5 : 1;
    uint8_t LED6 : 1;
    uint8_t LED7 : 1;
    uint8_t LED8 : 1;
} LEDStatus;

void displayAllStatusLed(LEDStatus status) {
    uint8_t *ptr = (uint8_t *)&status;
    for (int i = 0; i < 8; i++) {
        printf("LED %d: %d\n", i + 1, (*ptr >> i) & 1);
    }
}

int main() {
    LEDStatus status = { .LED1 = ENABLE, .LED3 = ENABLE, .LED5 = ENABLE, .LED7 = ENABLE };
    displayAllStatusLed(status);
    return 0;
}
```

---

## Ví dụ 4: Cấu hình ô tô với bitmask & bitfield

```c
#include <stdio.h>
#include <stdint.h>

#define COLOR_RED    0
#define COLOR_BLUE   1
#define COLOR_BLACK  2
#define COLOR_WHITE  3

#define POWER_100HP  0
#define POWER_150HP  1
#define POWER_200HP  2

#define ENGINE_1_5L  0
#define ENGINE_2_0L  1

#define SUNROOF_MASK         (1 << 0)
#define PREMIUM_AUDIO_MASK   (1 << 1)
#define SPORTS_PACKAGE_MASK  (1 << 2)

typedef uint8_t CarColor;
typedef uint8_t CarPower;
typedef uint8_t CarEngine;

typedef struct {
    uint8_t additionalOptions : 3;
    CarColor color : 2;
    CarPower power : 2;
    CarEngine engine : 1;
} CarOptions;

void configureCar(CarOptions *car, CarColor color, CarPower power, CarEngine engine, uint8_t options) {
    car->color = color;
    car->power = power;
    car->engine = engine;
    car->additionalOptions = options;
}

void setOption(CarOptions *car, uint8_t mask) {
    car->additionalOptions |= mask;
}

void unsetOption(CarOptions *car, uint8_t mask) {
    car->additionalOptions &= ~mask;
}

void displayCarOptions(const CarOptions car) {
    const char *colors[] = {"Red", "Blue", "Black", "White"};
    const char *powers[] = {"100HP", "150HP", "200HP"};
    const char *engines[] = {"1.5L", "2.0L"};

    printf("Car Configuration:\n");
    printf("Color: %s\n", colors[car.color]);
    printf("Power: %s\n", powers[car.power]);
    printf("Engine: %s\n", engines[car.engine]);
    printf("Sunroof: %s\n", (car.additionalOptions & SUNROOF_MASK) ? "Yes" : "No");
    printf("Premium Audio: %s\n", (car.additionalOptions & PREMIUM_AUDIO_MASK) ? "Yes" : "No");
    printf("Sports Package: %s\n", (car.additionalOptions & SPORTS_PACKAGE_MASK) ? "Yes" : "No");
}

int main() {
    CarOptions myCar;
    configureCar(&myCar, COLOR_BLACK, POWER_150HP, ENGINE_2_0L, 0);

    setOption(&myCar, SUNROOF_MASK);
    setOption(&myCar, PREMIUM_AUDIO_MASK);

    displayCarOptions(myCar);

    unsetOption(&myCar, PREMIUM_AUDIO_MASK);

    displayCarOptions(myCar);

    return 0;
}
```