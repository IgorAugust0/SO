package monitorjava;

public class ObjetoBuffer {

    private int memoria = -1;
    private boolean acessivel = true; // variavel booleana - condicao de escrita

    // metodo de escrita de dados na memoria
    public synchronized void escreveBuffer(int valor) {
        while (!acessivel) { // nao eh a vez de escrever
            try {
                wait(); //suspende a thread que chamou este metodo
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        System.err.println(Thread.currentThread().getName() +
                " produzindo o valor: " + valor);
        this.memoria = valor;

        acessivel = false;  // desabilita a memoria para escrita
        notify();  // libera uma thread que estah ESPERANDO devido a um wait( )
    }

    // metodo de leitura de dados na memoria
    public synchronized int lerBuffer() {

        while (acessivel) { // nao eh a vez de ler
            try {
                wait(); //suspende a thread que chamou este metodo
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        System.err.println(Thread.currentThread().getName() +
                " consumindo o valor: " + this.memoria);

        acessivel = true;  // libera buffer para escrita
        notify();  // libera uma thread que estah ESPERANDO devido a um wait( )
        return this.memoria;
    }
}



