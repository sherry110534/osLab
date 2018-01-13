import java.util.concurrent.locks.*;
public class ex2{
	private static Lock lock = new ReentrantLock();
	private static Condition threadCond = lock.newCondition();
	private static int product = 0;//empty

	//call by producer
	public static void setProduct(){
		lock.lock();//enter cs
		try{
			while(product >= 10){//full
				try{
					System.out.println("full");
					threadCond.await();
				}catch(InterruptedException e){
					e.printStackTrace();
				}
			}
			product++;
			System.out.printf("Produce~ amount (%d)%n", product);
			//signal consumer
			threadCond.signal();
		}
		finally{
			lock.unlock();//release cs
		}
	}
	public static void getProduct(){
		lock.lock();//enter cs
		try{
			while(product < 1){//empty, wait
				try{
					System.out.println("empty");
					//no product
					threadCond.await();
				}catch(InterruptedException e){
					e.printStackTrace();
				}
			}
			product--;
			System.out.printf("Consume~ amount (%d)%n", product);
			//singnal producer
			threadCond.signal();
		}
		finally{
			lock.unlock();
		}
	}
	//producer
	private static Runnable producer = new Runnable(){
		@Override
		public void run(){
			setProduct();
		}
	};
	//consumer
	private static Runnable consumer = new Runnable(){
		@Override
		public void run(){
			getProduct();
		}
	};
	public static void main(String[] args){
		Thread thread[] = new Thread[20];
		for(int i = 0; i < 20; i+=2){
			thread[i] = new Thread(producer);
		}
		for(int i = 1; i < 20; i+=2){
			thread[i] = new Thread(consumer);
		}
		for(int i = 0;i < 20; i++){
			thread[i].start();
		}
		try{
			for(int i = 0; i < 20; i++){
				thread[i].join();
			}
		}catch(InterruptedException e){
			System.out.println("join error");
		}
	}
}
