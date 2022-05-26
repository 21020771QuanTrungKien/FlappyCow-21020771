# FLAPPYCOW-21020771
## I. GIỚI THIỆU
  - 1. Game lấy cảm hứng từ chú bò sữa có cánh và trò flappy bird - game Việt nổi tiếng do Nguyễn Hà Đông phát triển năm 2013.
  - 2. Game được tạo bằng ngôn ngữ c++ và thư viện đồ họa SDL2
  - <img src="https://i.imgur.com/N86Z9BC.png">
## II. ĐẶC TRƯNG 
  - 1. CÁC CHỨC NĂNG CỦA FLAPPYCOW
    - Có menu game, exit menu khi thua.
    - Có bộ tính điểm hiện thị trên màn khi chơi.
    - dùng phím SPACE để diều khiển nhân vật (Cow ) vượt qua các chường ngại vật ( Đường ống, mặt đất, ...) .
    - Có sound effect khi cộng điểm, khi gameover.
  - 2. CÁC KĨ THUẬT LẬP TRÌNH
    - Thuật toán xử lý va chạm [AABB collision](https://tutorialedge.net/gamedev/aabb-collision-detection-tutorial/).
    - Sử dụng thư viện đồ họa [SDL2](https://www.libsdl.org/).
    - Lập trình hướng đối tượng (class).
    - con trỏ, cấp phát động.
  - 3. DEMO:
    - link youtube:
## III. CÁCH CÀI ĐẶT VÀ CHẠY GAME
  - Bước 1: tải Project.
    - CÁCH 1: Trên link Github, nhấn Code => Download file ZIP, hoặc nhấn download file này ==> [ZIP](https://github.com/21020771QuanTrungKien/FlappyCow-21020771/archive/refs/heads/master.zip).
    - CÁCH 2: Mở terminal tại thư mục muốn tải project, sử dụng lệnh git init để khởi tạo Git, sau đó dùng lệnh git clone https://github.com/21020771QuanTrungKien/FlappyCow-21020771 để clone project. (em làm project bằng phần mềm visual studio)
  - Bước 2: cài đặt.
    - CÁCH 1: chọn file Debug rồi nhấn vào file FlappyCow.exe là có thể chơi game luôn.
    - CÁCH 2: nếu muốn debug lại game thì chọn FlappyBird.sln(visual studio) ta chọn debug dưới dạng x86 rồi ta nhấn f5 hoặc tổ hợp ctrl+f5 để Debug là có thể chơi game. (không cần cài đặt SDL2, SDL_Image, SDL_TTF và SDL_Mixer vì các tệp .dll đã có trong file Debug)
## IV. KẾT LUẬN
  Do là dự án game đầu tiên nên em còn bí ý tưởng còn phải tham khảo một số video hướng dẫn trên youtube và còn nhiều sai xót, code chưa được clean, mong nhận được sự góp ý của các thầy và mọi người.
  Hướng phát triển game tiếp theo sẽ là:
    - có tab pause để tạm dừng trò chơi.
    - có hệ thống high score và huy chương với mỗi số điểm tưởng ứng.
    - Mặt đất, các nhân vật chuyển động khiến trò chơi trở nên chân thực hơn.
    - Hệ thống game sẽ ngày càng khó khi điểm cao, các block có thể di chuyển khi chơi đến số điểm cao.
  Sau khi hoàn thành dự án kinh nghiệm em rút ra được là cách quản lý một project, biết câch chia từng file object, class để quản lý .Việc làm game đã tiếp cho em thêm động lực lập tình cho bản thân em vì bản thân em tự thấy em rất lười lập trình. Tuy đây là một dự án được coi là khá đơn giản không có gì phức tạp nhưng mong được mọi người giúp đỡ ạ.
  
