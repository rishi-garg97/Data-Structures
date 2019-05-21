
public class Main
{
	public static void main(String[] args) {
		
			System.out.print("Enter String : ");
			java.util.Scanner s = new java.util.Scanner(System.in);
			String in = s.nextLine();
			
		char ch;
		int ch1,sum=0;
		
		for(int i=0;i<in.length();i++){
		   ch = in.charAt(i);
		   ch1=ch;
		   if(ch1>=48&&ch<=57)
		     sum = sum+Character.getNumericValue(ch1);
		}
		
		System.out.print("Sum of no in "+in +" is -> "+sum);
		
	}
}