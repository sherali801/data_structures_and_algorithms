package lab1.task2.PrimeNumber;

import java.util.*;

/**
 * This application displays the first given prime numbers
 * @author sherali
 */
public class PrimeNumber {

  /**
   * @param num: number to be checked for prime or not
   * @return true if prime otherwise false
   */
	private static boolean isPrime(int num) {
		for (int i = 2; i <= Math.sqrt(num); i++) {
			if (num % i == 0) {
				return false;
			}
		}
		return true;
	}
	
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
    int num = 0, count = 0, i = 2;
    do {
      System.out.print("Enter No. of Prime Numbers: ");
        num = input.nextInt();
    } while (num < 1);
    while (count < num) {
        if (isPrime(i)) {
            System.out.print(i + " ");
            count++;
        }
        i++;
    }
	}
  
}
