package monitorjava;

public class Main {

    public static void main(String args[]) {
        ObjetoBuffer umBuffer = new ObjetoBuffer();

        // criacao das threads
        Produtor umProdutor = new Produtor(umBuffer);
        Consumidor umConsumidor = new Consumidor(umBuffer);

        // start threads em concorrência
        umProdutor.start();
        umConsumidor.start();
    }
}  // fim da classe Principal

