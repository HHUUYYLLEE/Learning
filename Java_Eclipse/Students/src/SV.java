import java.util.Scanner;
public class SV {
		public static void main(String[] args) {
			double moreMoney;
			double withdrawMoney;
			int menu;
			Scanner enter = new Scanner(System.in);
			account tk = new account("Lê Bá Huy", 4586);
			while(true) {
				System.out.print("1. Thông tin\n2. Thêm tiền\n3. Rút tiền\nKhác: Thoát\nChọn: ");
				menu = enter.nextInt();
				switch(menu) {
			case 1:
				tk.thongTin();
				break;
			case 2:
				System.out.print("\tThêm bao nhiêu: ");
				moreMoney = enter.nextDouble();
				tk.themTien(1000);
				break;
			case 3:
				System.out.print("\tRút bao nhiêu: ");
				withdrawMoney = enter.nextDouble();
				tk.rutTien(withdrawMoney);
				break;
			default:
				System.out.print("\tThoát.");
				System.exit(0);
				}
			}
		}
}
