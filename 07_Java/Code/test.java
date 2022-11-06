class Man
{
  int a;
  int b;

  public void setA(int a) { this.a = a; }
  public void setB(int b) { this.b = b; }
  public int getA() { return a; }
  public int getB() { return b; }
}

public class test 
{
  public static void main(String[] args) 
  {
    System.out.println("Hello World");
    Man m = new Man();
    m.setA(10);
    m.setB(20);
    System.out.println(m.getA());
    System.out.println(m.getB());
  }
}