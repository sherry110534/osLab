//race condition
public class ex1_2{
	public static int c = 0;
	public static void inc(){
		for(int i = 0; i < 25000000; i++){
			c++;
		}
	}
	public static void dec(){
		for(int i = 0; i < 25000000; i++){
			c--;
		}
	}
	private static Runnable increase = new Runnable(){
		@Override
		public void run(){
			inc();
		}
	};
	private static Runnable decrease = new Runnable(){
		@Override
		public void run(){
			dec();
		}
	};


	public static void main(String[] args){
		Thread thread[] = new Thread[4];
		for(int i = 0; i < 4; i+=2){
			thread[i] = new Thread(increase);
		}
		for(int i = 1; i < 4; i+=2){
			thread[i] = new Thread(decrease);
		}
		for(int i = 0; i < 4; i++){
			thread[i].start();
		}
		try{
			for(int i = 0; i < 4; i++){
				thread[i].join();
			}
		}catch(InterruptedException e){
		}
		System.out.printf("(%d)%n", c);
	}
}
