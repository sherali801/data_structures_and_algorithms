package lab1.task3;

import java.util.*;
import lab1.task3.models.Student;

/**
 * This application takes the number of students and calculate their average age.
 * @author sherali
 */
public class Index {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    int num = 0;
    String name = "";
    float age = 0;
    do {
      System.out.print("Enter Number of Students: ");
        num = input.nextInt();
    } while (num < 1);
    Student[] std = new Student[num];
    for (int i = 0; i < num; i++) {
      std[i] = new Student();
      System.out.println("Student # " + (i + 1) + ":");
      std[i].setId(i + 1);
      System.out.print("Student # " + (i + 1) + " Name: ");
      name = input.next();
      std[i].setName(name);
      do {
          System.out.print("Student # " + (i + 1) + " Age: ");
          age = input.nextFloat();
      } while (age <= 0);
      std[i].setAge(age);
    }
    System.out.println("\nAverage: " + (Student.calcAverage(std, num)));
  }
}
