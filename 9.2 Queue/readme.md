
# Hàng đợi (Queue)


## 1. Định nghĩa

Queue là một cấu trúc dữ liệu tuân theo nguyên tắc "First in, First out" (FIFO), nghĩa là phần tử đầu tiên được thêm vào hàng đợi sẽ là phần tử đầu tiên được lấy ra
## 2. Các thao tác cơ bản
| Tên thao tác | Mô tả |
| :--- | :--- |
| enqueue(x) | Thêm phần tử x vào cuối hàng đợi |
| dequeue() | Xóa phần tử từ đầu hàng đợi (`front()`) |
| front() | Trả về giá trị phần tử ở đầu hàng đợi |
| near() | Trả về giá trị phần tử ở cuối hàng đợi |
| is_empty() | Kiểm tra hàng đợi rỗng |
| is_full() | Kiểm tra hàng đợi đầy |


## 3. Các loại hàng đợi

### Linear Queue: 
- Hàng đợi tuyến tính, có giới hạn và không tái sử dụng được không gian bị bỏ trống phía trước.
- Nếu `rear` đạt tới max, thì quere được coi là đầy và không thể thêm phần tử mới, ngay cả khi phía trước còn khoảng trống do các phần tử đã bị xóa
- Chỉ có thể thêm phần tử mới khi đã dequeue toàn bộ các phần tử hiện có (tức là queue rỗng hoàn toàn và front được reset về vị trí ban đầu).

### Circular Queue: 
- Hàng đợi vòng tròn, tận dụng được không gian đã được giải phóng.
- Khi rear đạt tới size - 1 và không còn chỗ trống từ phía cuối, nếu front đã di chuyển (nghĩa là đã có các phần tử được dequeue), rear có thể "quay vòng" về vị trí 0 để tận dụng khoảng trống.

- Priority Queue: Hàng đợi ưu tiên.
## 4. Điều kiện kiểm tra trạng thái

### Linear Queue
- Hàng đợi rỗng khi: `front == -1` hoặc `front > rear`
- Hàng đợi đầy khi: `rear == size - 1`

### Circular Queue
- Hàng đợi rỗng khi: `front == -1`
- Hàng đợi đầy khi : `front == (rear + 1) % size`