
# Bài 11: JSON


## 1. Khái niệm

JSON (JavaScript Object Notation) là một định dạng truyền tải dữ liệu phổ biến trong lập trình và giao tiếp giữa các máy chủ và trình duyệt web
Mỗi đối tượng JSON bao gồm một tập hợp các cặp "key" và "value", trong khi mỗi mảng JSON là một tập hợp các giá trị
## 2. Các định dạng
### Object
```c
{ 
  "name": "John Doe",
  "age": 30,
  "city": "New York",
  "isStudent": false,
  "grades": [85, 90, 78]
}
```
### Mảng JSON
```c
[
    {
        "name": "DAT",
        "age": 22,
        "city": "Da Nang",
        "isStudent": false,
        "grades": [85, 90, 78]
    },
    {
        "name": "DAT2",
        "age": null,
        "city": "Da Nang",
        "contact": {
            "email": "jane.smith@example.com",
            "phone": "555-1234"
        }
    },
    {
        "name": "Bob Johnson",
        "age": 35,
        "city": "Chicago"
    },
    20, 3.14, "Hello World", true, null, [80, 70, 90]
]
```
```c
typedef enum 
{
    JSON_NULL,
    JSON_BOOLEAN,
    JSON_NUMBER,
    JSON_STRING,
    JSON_ARRAY,
    JSON_OBJECT
} JsonType;
```