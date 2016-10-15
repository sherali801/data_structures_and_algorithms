package lab1.task3.models;

/**
 * This application takes the number of students and calculate their average age.
 * @author Sher Ali
 */
public class Student {
  private int studentId;
  private String studentName;
  private float studentAge;
  public Student() { }
  /**
   * 
   * @param id: sets id of the student
   * @param name: sets name of the student
   * @param age: sets age of the student
   */
  public Student(int id, String name, float age) {
      this.studentId = id;
      this.studentName = name;
      this.studentAge = age;
  }
  /**
   * @param id: sets id of the student 
   */
  public void setId(int id) { this.studentId = id; }
  /**
   * @param name: sets name of the student 
   */
  public void setName(String name) { this.studentName = name; }
  /**
   * @param age: sets age of the student 
   */
  public void setAge(float age) { this.studentAge = age; }
  /**
   * @return: return id of the student 
   */
  public int getId() { return this.studentId; }
  /**
   * @return: return name of the student 
   */
  public String getName() { return this.studentName; }
  /**
   * @return: return age of the student 
   */
  public float getAge() { return this.studentAge; }
  /**
   * @param std: array of student objects
   * @param num: number of total students
   * @return average of students ages
   */
  public static float calcAverage(Student[] std, int num) {
    float avg = 0;
    for (int i = 0; i < num; i++) {
            avg += std[i].getAge();
    }
    return avg / num;
  }
}
