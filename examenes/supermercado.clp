(deftemplate producto
    (slot id)
    (slot nombre)
    (slot ubi (type INTEGER) (range 1 12))
    (slot stock (type INTEGER))
    (slot precio)
)

(deftemplate pedido
    (slot idCliente)
    (slot idProducto)
    (slot unidades (type INTEGER))
)

(deftemplate carroCompra
    (slot idCliente)
    (slot nArticulos)
    (slot importeTotal)
    (slot ubiAgente)
)

(deffunction incremento (?num)
    (+ ?num 1)
)

(deffunction suma (?num1 ?num2)
    (+ ?num1 ?num2)
)

(defrule asignaCarro
    ?n <- (nuevoCliente ?idN)
    =>
    (assert (carroCompra (idCliente ?idN) (nArticulos 0) (importeTotal 0) (ubiAgente 1)))
    (retract ?n)
)

(defrule moverCarro
    (pedido (idProducto ?idP) (idCliente ?idC))
    (producto (id ?idP) (ubi ?pasillo))
    ?c <- (carroCompra (idCliente ?idC) (ubiAgente ?ubi))
    (test (neq ?pasillo ?ubi))
    =>
    (modify ?c (ubiAgente (+ (mod ?ubi 12) 1)))
)

(defrule comprar
    (declare (salience 10))
    ?ped <- (pedido (idProducto ?idP) (idCliente ?idC) (unidades ?uds))
    ?prod <-(producto (id ?idP) (ubi ?ubi) (stock ?s) (precio ?prec))
    ?carro <- (carroCompra (idCliente ?idC) (nArticulos ?nArts) (importeTotal ?importe) (ubiAgente ?ubi))
    (test (>= ?s ?uds))
    =>
    (modify ?prod (stock (- ?s ?uds)))
    (modify ?carro (nArticulos (+ ?nArts ?uds)) (importeTotal (suma ?importe (* ?uds ?prec))))
    (retract ?ped)
)

(defrule existenciasInsuficientes
    ?ped <- (pedido (idProducto ?idP) (unidades ?uds))
    ?prod <-(producto (id ?idP) (stock ?s))
    (test (< ?s ?uds))
    =>
    (printout t "Stock insuficiente" crlf)
    (retract ?ped)
)

(deffacts iniciales
    (producto (id 1) (nombre leche) (ubi 3) (stock 45) (precio 1))
    (producto (id 2) (nombre galletas) (ubi 4) (stock 10) (precio 2.20))
    (producto (id 3) (nombre cafe) (ubi 5) (stock 2) (precio 2.6))
    (producto (id 4) (nombre arrow) (ubi 12) (stock 30) (precio 1.98))
)



