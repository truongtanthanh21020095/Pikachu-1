Trương Tấn Thành - 21020095  
Bài tập cuối khóa Lập Trình Nâng cao - Game Pikachu

I, Hướng dẫn cài đặt:
	1. Tải game chơi trục tiếp 
	- Truy cập link: https://drive.google.com/file/d/1b3KjHHQB0X_Sh-z5HBw_no849lLWYNWO/view?usp=sharing
	- Tải file về và giải nén 
	- Mở file Pikachu_PlayGame vừa giải nén được, chạy file Pikachu-1.exe để bắt đầu trò chơi 

	2. Chạy project game bằng Visual Studio (Nếu cách 1 không chạy được)
	- Clone project game về: https://github.com/truongtanthanh21020095/Pikachu-1
	- Máy yêu cầu cài: 
		+ Visual Studio
		+ SDL 2 (https://phattrienphanmem123az.com/lap-trinh-game-c-p2/game-cpp-phan-2-cai-dat-project.html?fbclid=IwAR3q95AWeaa69iDMsZlMlVRTtEG2K7KgeJgaY8_GEyHFUpUNu8AOVDjQDe8) 
	- Chạy tệp Pikachu-1.sln bằng Visual Studio để mở và chạy project
II, Mô tả chung về trò chơi và chức năng
- Game có đồ họa hình ảnh, âm thanh sống động. Giao diện dễ sử dụng, đơn giản. thích hợp để giải trí nhẹ, 
luyện tập mắt, khả năng tìm kiếm, tư duy. 
- Sử dụng các thao tác bằng chắc click vào chuột.
- Khi trò chơi bắt đầu sẽ có một bảng có kích thước 9 * 16, với mỗi vị trí có hình ảnh của một Pokémon.
- Người chơi sẽ phải chọn 2 pokemon giống nhau để làm chúng biến mất, điểu kiện là sao cho
đường nối giữa hai Pokémon được chọn có số đường gấp khúc nhỏ hơn bằng hai. Điểm số được tính theo khoảng cách giữa 
cặp pokemon đó, càng xa nhau càng được nhiều điểm.
- Trò chơi có chức năng tạm dừng, lưu lại màn chơi mỗi khi bạn thoát game đúng quy trình.
- Có hệ thống level.
- Sau mỗi vãn chơi bạn sẽ nhận được thêm một gợi ý.

III, Các kỹ thuật dùng để xử lý khi lập trình:
- Sử dụng thư viện đồ họa SDL2
- Mảng, struct, đọc ghi file txt......

IV, Hướng phát triển 
- Cải tiến đồ họa cho đẹp hơn 
- Có thêm nhiều hệ thống levels cho người chơi
- Hướng tới chế độ multiplayer để cho 2 hoặc nhiều người chơi có thể so tài với nhau
