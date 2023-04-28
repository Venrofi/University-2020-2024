package myfactorial_Terelak;

public aspect Remainder {
    int around(int n) : execution(int factorial(int)) && args(n) {
    	n = Math.abs(n);
    	if (n<2)
			 return proceed(n);
		 else
			 return n * Math.factorial(n-1);
    }
}
