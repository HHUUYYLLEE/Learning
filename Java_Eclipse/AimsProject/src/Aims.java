
public class Aims {

	public static void main(String[] args) {
		 Order anOrder = new Order();
		   // Create a new dvd object and set the fields
		   DigitalVideoDisc dvd1 = new DigitalVideoDisc("Batman & Robin");
		   dvd1.setCategory("superhero film");
		   dvd1.setCost(29.96f);
		   dvd1.setDirector("Joel Schumacher");
		   dvd1.setLength(87);
		   anOrder.addDigitalVideoDisc(dvd1);
		   
		   DigitalVideoDisc dvd2 = new DigitalVideoDisc("Avengers: Infinity War");
		   dvd2.setCategory("superhero film");
		   dvd2.setCost(14.56f);
		   dvd2.setDirector("Anthony Russo/Joe Russo");
		   dvd2.setLength(124);
		   anOrder.addDigitalVideoDisc(dvd2);
		   
		   DigitalVideoDisc dvd3 = new DigitalVideoDisc("Back to the Future");
		   dvd3.setCategory("Science fiction");
		   dvd3.setCost(30.99f);
		   dvd3.setDirector("Robert Zemeckis");
		   dvd3.setLength(90);
		   anOrder.addDigitalVideoDisc(dvd3);
		   System.out.print("Total Cost is: ");
		   System.out.print(anOrder.totalCost());
		   System.out.print("$");
	}

}
