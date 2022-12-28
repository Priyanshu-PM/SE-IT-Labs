package Assignment10;

public class CarFactory {
    public Car buildCar(Cartype ctype) {
        switch(ctype) {
            
            case SMALL:
                return new SmallCar();

            case SEDAN:
                return new SedanCar();

            case LUXURY:
                return new LuxuryCar();

            case HETCHBACK:
                return new HetchBackCar();
        }
        return null;
    }
}
