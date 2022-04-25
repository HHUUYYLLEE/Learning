
public class account {
	private String tenTaiKhoan;
	private double soDu;
	

	public String getTenTaiKhoan() {
		return tenTaiKhoan;
	}

	public void setTenTaiKhoan(String tenTaiKhoan) {
		this.tenTaiKhoan = tenTaiKhoan;
	}

	public double getSoDu() {
		return soDu;
	}

	public void setSoDu(double soDu) {
		this.soDu = soDu;
	}

	public account(String tenTaiKhoan, double soDu) {
		super();
		this.tenTaiKhoan = tenTaiKhoan;
		this.soDu = soDu;
	}
	   
	public void thongTin() {
		System.out.println("\tTên tài khoản là: "+ tenTaiKhoan +"\n"+ "\tSố dư: "+ soDu +"$");
	}
	   
	public void rutTien(double wihtdrawMoney) {
		if(wihtdrawMoney <= soDu) {
			soDu -= wihtdrawMoney;
			System.out.println("\tSố tiền còn lại: "+ soDu + "$");
		} else {
			System.out.println("\tKhông thể rút nhiều hơn số tiền còn lại.");
		  }
	}
	   
	public void themTien(double moreMoney) {
		   soDu += moreMoney;
		   System.out.println("\tSố tiền được thêm: "+ moreMoney + "$");
		   System.out.println("\tSố tiền sau khi được thêm: "+ soDu + "$");
	}
}
