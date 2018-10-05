class Euc_GCD{
	public static int GCD(int a, int b){
		if(b==0){
			return a;
		}
		else{
			return GCD(b,(a%b));
		}
	}

	public static void main(String args[]){
		int num1=10, num2=20;

		int gcd=GCD(num1,num2);

		System.out.println("The GCD of "+num1+" & "+num2+" is: "+gcd);
	}
}