/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package monitorjava;
public class Consumidor extends Thread {

    private ObjetoBuffer um_Buffer;
    // Construtor do Consumidor thread object
    public Consumidor(ObjetoBuffer dado) {
        super("Consumidor");
        um_Buffer = dado;
    }

    // Thread Consumidor lerah o buffer 10 vezes em intervalos aleatorios
    public void run() {
        int valor, soma = 0;

        do {

            // dorme por um intervalo aleatorio
            try {
                Thread.sleep((int) (Math.random() * 3000));
            } // Tratamento de excecao
            catch (InterruptedException exception) {
                System.err.println(exception.toString());
            }

            valor = um_Buffer.lerBuffer();
            soma += valor;

        } while (valor != 10);

        System.err.println(
                getName() + " terminou de consumir. Totalizou: " + soma);
    }
}
