
# Stack
## 1. Định nghĩa

Stack là một cấu trúc dữ liệu tuyến tính, tuân theo nguyên tắc LIFO – Last In, First Out. Tức là phần tử được thêm vào sau cùng sẽ là phần tử đầu tiên được lấy ra.
## 2. Các thao tác cơ bản

| Tên thao tác | Mô tả |
| :--- | :--- |
| push(x) | thêm 1 phần tử vào đỉnh của stack |
| pop | xóa 1 phần tử ở đỉnh stack |
| peek() hoặc top() | lấy giá trị phần tử ở đỉnh stack |
| is_empty() | kiểm tra stack rỗng |
| is_full() | kiểm tra stack đầy |

## 3. Điều kiện kiểm tra trạng thái

- stack đầy khi top = size - 1
- stack rỗng khi top =- 1

## 4. Cách hoạt động

- Khi push, tăng top rồi gán phần tử vào items[top].
- Khi pop, trả về items[top] rồi giảm top.

```c
push -> top++
pop -> top--
```