import java.util.concurrent.locks.*;

public class ex2_1 implements Runnable{
	private Lock lock = new ReentrantLock();
	private Condition threadCond = lock.newCondition();
	public int  key = 1;
	//-1  is empty
	private int product = 0;
	public void run(){
		if(key % 2 == 1)
		{
			key++;
			for(int i = 0; i < 100;i++){
				setProduct();
			}
		}else
		{
			key++;
			for(int i = 0;i < 100;i++){
				getProduct();
			}
		}
	}

	//call by product
	public void setProduct(){
		lock.lock();
		try{
			while(this.product >= 10){
				try{
					//ex2 is full and producer wait
					System.out.printf("-----------\n");
					System.out.printf("--Is full--\n");
					System.out.printf("-----------\n");
					threadCond.await();
				}
				catch(InterruptedException e){
					e.printStackTrace();
				}
			}
			if(this.product == -1){
				this.product +=2;
			}
			else {
				this.product++;
			}


			System.out.printf("To produce ,amount(%d)\n",this.product);

			// signal consumer
			threadCond.signal();
		}
		finally {
			lock.unlock();
		}
		//can preemptive
		for(int i=0;i <100000;i++){}
	}

	public void getProduct(){
		lock.lock();
		try{
			while(this.product == -1){
				try{
					//no product
					System.out.printf("------------\n");
					System.out.printf("--Is empty--\n");
					System.out.printf("------------\n");
					threadCond.await();
				}
				catch(InterruptedException e){
					e.printStackTrace();
				}   
			}
			this.product--;
			System.out.printf("To consume ,amount(%d)\n",this.product);

			//signal producer
			threadCond.signal();
		}
		finally{
			lock.unlock();
		}
		//can preemptive
		for(int i=0;i <100000;i++){}
	}

	public static void main(String[] args) {
		ex2_1 Syc = new ex2_1();
		Thread thread0 = new Thread(Syc);
		Thread thread1 = new Thread(Syc);

		thread0.start();
		thread1.start();

		try{
			thread0.join();
			thread1.join();
		}catch(InterruptedException e){}

	}
}
