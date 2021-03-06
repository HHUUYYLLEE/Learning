
public class Order {

	public static final int MAX_NUMBERS_ORDERED = 10;
	private DigitalVideoDisc itemsOrdered[] = new DigitalVideoDisc[MAX_NUMBERS_ORDERED];
	private int qtyOrdered = 0;
	void addDigitalVideoDisc(DigitalVideoDisc disc){
		if(qtyOrdered < 10){
			itemsOrdered[qtyOrdered] = disc;
			qtyOrdered++;
		} else System.out.println("Full orders.");
		
	}
	void removeDigitalVideoDisc(DigitalVideoDisc disc){
		for(int i = 0; i < qtyOrdered; ++i){
			if(itemsOrdered[i] == disc) 
				for(int j = i; j < qtyOrdered - 1; ++j) {
					itemsOrdered[j] = itemsOrdered[j + 1];
					itemsOrdered[j + 1] = null;
				}
		}
		qtyOrdered--;
	}
		
	float totalCost() {
		float total = 0;
		for(int i = 0; i < qtyOrdered; ++i) {
			total += itemsOrdered[i].getCost();
		}
		return total;
}
}