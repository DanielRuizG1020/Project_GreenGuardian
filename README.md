# Project_GreenGuardian
Elaborado por
Andres Felipe Penagos Betancur 1036686915
Daniel Ruiz Guirales 1036688095

El objetivo principal de este proyecto es diseñar e implementar un sistema de control avanzado para invernaderos que permita monitorear y regular de manera precisa diversas variables ambientales. Estas variables incluyen temperatura, humedad, pH, luminosidad y nivel de agua, fundamentales para el óptimo crecimiento y desarrollo de cultivos en un entorno controlado.

Para la regulación de la temperatura y la humedad, se implementará un sistema de retroalimentación que activará ventiladores y sistemas de riego automatizados en función de los valores registrados por los sensores correspondientes. Asimismo, se dispondrá de una fuente de luz artificial controlada electrónicamente para ajustar la luminosidad dentro del invernadero según las necesidades de los cultivos.

En lo que respecta al pH y al nivel de agua, el sistema se enfocará en la monitorización continua de estos parámetros, proporcionando información detallada sobre su evolución a lo largo del tiempo. Se integrarán sensores de pH y nivel de agua de alta precisión para garantizar una medición confiable y precisa.

Como valor añadido, el sistema permitirá visualizar el estado de las variables ambientales en tiempo real a través de displays ubicados estratégicamente dentro del invernadero. Además, se habilitará la posibilidad de acceder a estos datos de manera remota mediante una aplicación móvil, lo que facilitará el monitoreo y control del invernadero desde cualquier ubicación.

#Requisitos funcionales

Procesamiento de Datos:
-Se espera que el sistema recolecte datos provenientes de sensores de temperatura, humedad,
luminosidad, pH y nivel de agua con una frecuencia de muestreo ajustable.
-El sistema deberá aplicar algoritmos específicos para cada variable ambiental con el propósito de
analizar valores promedio, desviaciones estándar y tendencias temporales de los datos
capturados.
Comunicación:
-El sistema deberá ser capaz de intercambiar información con dispositivos externos, como
pantallas de visualización y dispositivos móviles, mediante interfaces de comunicación estándar
como UART, SPI o I2C.
-Se buscará la implementación de interfaces de comunicación que permitan la configuración
remota de parámetros y la consulta de datos ambientales desde dispositivos externos.
Control:
-El sistema deberá activar y desactivar ventiladores y sistemas de riego de forma automática,
ajustándose a umbrales predefinidos para la temperatura y la humedad.
-Se encargará de regular la intensidad de la fuente de luz artificial según la luminosidad ambiental
medida por los sensores.
-El sistema emitirá alertas visuales y/o audibles en caso de que alguna variable ambiental
sobrepase los límites establecidos.
Interfaz de Usuario:
-El sistema deberá ofrecer una interfaz de usuario intuitiva y fácil de utilizar para la visualización
del estado de las variables ambientales y la configuración de parámetros.
-Los datos en tiempo real, incluyendo valores actuales y alertas, serán mostrados en displays
ubicados dentro del invernadero.
-Se permitirá el acceso remoto mediante una aplicación móvil, que proporcionará una interfaz
amigable para el monitoreo y control desde cualquier ubicación.

#Requisitos no Funcionales

Rendimiento:
Se espera que el sistema integrado procese los datos de los sensores y ejecute los algoritmos de
control dentro de un tiempo máximo de respuesta de 200 milisegundos para asegurar una
reacción rápida a las variaciones del entorno. Asimismo, la frecuencia de muestreo de los sensores
deberá rondar los 5 Hz para garantizar una recolección apropiada de los datos.
Disponibilidad:
Se busca que el sistema sea estable y confiable en su operación, con una tasa de fallos inferior al
10%, lo que aseguraría su disponibilidad durante la mayor parte del tiempo de funcionamiento
previsto.
Escalabilidad:
El diseño del sistema debe contemplar la capacidad de gestionar un conjunto moderado de
sensores y actuadores, con flexibilidad para su ampliación en el futuro según las necesidades.
Mantenibilidad:
Es crucial que el código del sistema esté exhaustivamente documentado y siga las mejores
prácticas de programación, facilitando así su mantenimiento y actualización por parte de los
desarrolladores a lo largo del tiempo.
Usabilidad:
La interfaz de usuario del sistema debe ser intuitiva y fácil de usar, con características básicas que
faciliten la visualización de datos y su manipulación por parte del usuario.
Consumo de Energía:
Se espera que el sistema administre eficientemente el consumo de energía para prolongar la
duración de la batería, manteniendo un consumo óptimo para su funcionamiento eficiente.
Tiempos de Respuesta:
El sistema debe responder a las solicitudes de control y visualización de datos en un máximo de
500 milisegundos para asegurar una experiencia de usuario satisfactoria.
Tolerancia a Fallos:
Es fundamental que el sistema pueda identificar y gestionar de manera efectiva los errores o fallas
menores, minimizando su impacto en el funcionamiento general del sistema y garantizando su
continuidad operativa.
Portabilidad:
El sistema embebido deberá ser diseñado de manera que sea fácilmente transportable entre
diferentes ubicaciones o entornos. Esto implica que el sistema deberá ser compacto y liviano, con
la capacidad de ser instalado y desinstalado de manera rápida y sencilla. Además, se requerirá que
el sistema sea compatible con fuentes de alimentación móviles, como baterías recargables, paragarantizar su funcionamiento independientemente de la disponibilidad de energía en el lugar de
destino.


#Escenario

-Se construirá una maqueta a escala del invernadero que se utilizará para simular las condiciones ambientales reales. La maqueta incluirá áreas designadas para la instalación de sensores de temperatura, humedad, pH y luminosidad, así como para los actuadores como ventiladores y sistemas de riego.

-Se designarán áreas específicas dentro del invernadero maqueta para realizar pruebas de control de temperatura, humedad, pH y luminosidad. Se simularán diferentes condiciones ambientales para probar la capacidad del sistema para ajustar y mantener las variables dentro de los rangos deseados.


