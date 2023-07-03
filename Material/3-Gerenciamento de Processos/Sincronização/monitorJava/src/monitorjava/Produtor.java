package monitorjava;
public class Produtor extends Thread {
   private  ObjetoBuffer o_Buffer;

   // construtor da Thread Produtor
   public Produtor( ObjetoBuffer dado )
   {
      super( "Produtor" );
      o_Buffer = dado;
   }

   // Thread do Produtor escrevera 10 vezes no buffer em intervalos de tempo aleatorios
    @Override
   public void run()
   {
      for ( int i = 1; i <= 10; i++ ) {

         // dorme por um tempo aleatorio
         try {
            Thread.sleep( ( int ) ( Math.random() * 3000 ) );
         }

         // tratamento de excecao
         catch( InterruptedException exception ) {
            System.err.println( exception.toString() );
         }

         // chama metodo do objeto buffer
        o_Buffer.escreveBuffer( i );
      }

      System.err.println(getName() + " terminou de produzir");
   }

}
