public class Singleton {
    private static Singleton single;
    private Singleton() {}
    private static Singleton getInstance() {
        if (single == null) {
            single = new Singleton();
            System.out.println("New!");
        }
        return single;
    }
    
    public static void main(String []args){
        Singleton obj1 = getInstance();
        Singleton obj2 = getInstance();
        Singleton obj3 = getInstance();
    }
}
