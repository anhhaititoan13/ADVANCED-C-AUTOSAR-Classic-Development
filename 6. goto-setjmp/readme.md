# Bài 6: `goto` và thư viện `setjmp.h` trong C

## Giới thiệu

Bài học này giới thiệu hai kỹ thuật điều khiển luồng chương trình đặc biệt trong ngôn ngữ C:

- Từ khóa `goto` để nhảy điều kiện giữa các nhãn.
- Thư viện `setjmp.h` để xử lý ngoại lệ.

---

## Goto trong C

`goto` cho phép nhảy đến một **label (nhãn)** cụ thể trong cùng một hàm. Nó cung cấp sự kiểm soát mạnh nhưng thường gây rối logic nếu lạm dụng.

### Ví dụ cơ bản:
```c
#include <stdio.h>

int main() {
    int i = 0;

start:
    if (i >= 5) {
        goto end;
    }
    printf("%d ", i);
    i++;
    goto start;

end:
    printf("\n");
    return 0;
}
```

### Mô phỏng đèn giao thông:
```c
switch (state) {
    case RED:
        // xử lý
        state = GREEN;
        goto skip_sleep;
    // ...
}
skip_sleep:;
```

---

## Ứng dụng `goto` nâng cao

Ví dụ mô phỏng ma trận LED hiển thị từ ký tự `'HI'`, `'FASHION'`, `'SUITABLE'`, nhảy giữa các trạng thái bằng `goto`.

### Giao diện sử dụng:
- Dùng `switch-case` với `enum Sentence`.
- Có thể nhấn phím `'M'` để **thoát vòng lặp** và dùng `goto exit_loops;`.

```c
if ((button = is_pressed_stop_key()) == 1)
    goto exit_loops;
```

---

## Thư viện `setjmp.h`

### Công dụng:
Giúp thực hiện **xử lý ngoại lệ** trong C (như `try-catch` trong C++/Java).

### Nguyên lý:
- `setjmp(jmp_buf env)` đánh dấu vị trí quay lại.
- `longjmp(env, val)` quay lại nơi đã gọi `setjmp`.

### Ví dụ:
```c
#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;
int exception = 0;

void func2() {
    longjmp(buf, 2);
}

void func3() {
    longjmp(buf, 3);
}

void func1() {
    exception = setjmp(buf);

    if (exception == 0) {
        func2();
    } else if (exception == 2) {
        func3();
    } else if (exception == 3) {
        printf("Exception = %d\n", exception);
    }
}
```

---

##  Xử lý ngoại lệ (Exception Handling)

### Một số loại ngoại lệ phổ biến:
- Chia cho 0.
- Truy cập ngoài mảng.
- Truy cập con trỏ NULL.
- Lỗi mở/tệp tin hoặc cấp phát bộ nhớ.

###  Cấu trúc tiêu biểu (C++/Java):
```cpp
try {
    // Khối có thể gây lỗi
} catch (ExceptionType e) {
    // Xử lý lỗi
} catch (...) {
    // Xử lý tất cả lỗi khác
}
```

---

## Lưu ý

- Tránh lạm dụng `goto` gây khó bảo trì mã nguồn.
- `setjmp/longjmp` hữu ích nhưng nên dùng khi thực sự cần thiết.
- Ngôn ngữ hiện đại ưu tiên `try-catch` hơn vì rõ ràng và dễ bảo trì.

---


