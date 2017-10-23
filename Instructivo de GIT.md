# Instructivo de pasos a seguir cuando usen GIT en este trabajo:


#### \*SIEMPRE leer la sección 6 antes de trabajar. :smile: :+1:

| **Contenido**                                                     |
| ----------------------------------------------------------------- |
| 1. [**Clonando archivos desde github**](#clonar-un-repositorio)   |
| 2. [**Cambiar/crear/borrar branch (Rama)**](#cambios-de-branch)   |
| 3. [**Trabajar en los archivos**](#archivos)                      |
| 4. [**Actualizar el repositorio**](#commits)                      |
| 5. [**Código a integrar**](#merge)                                |
| 6. [**Recordatorio**](#importante)                                |
| 7. [**Problemas comunes y cómo resolverlos**](#problemas)         |
| 8. [**TL;DR**](#resumen)                                          |
| 9. [**Fotos y ejemplos**](#fotos-y-ejemplos)                      |


## **Requisito previo**: haber descargado e instalado GIT bash

Git bash puede descargarse desde [**acá**](https://git-scm.com/downloads).

---


## Clonar un repositorio:

#### Ir a la carpeta donde van a guardar los archivos.

1. Darle **click derecho** y clickear la opción **git bash here**.
2. Tipear o copiar y pegar\* el comando `git clone <url del repositorio>`
3. Acá se puede proseguir de dos formas distintas:
  - O se cierra la consola, se va a la carpeta TP_Integrador y nuevamente repite el paso 1.
  - Tipear `cd TP_Integrador` en la consola (`cd` significa *change directory*).
4. Ahora se estará en el directorio y el repositorio estará en el *branch* **__master__**.
5. Ver paso siguiente para saber como importar los branches existentes.

\*Recuerde que no funciona usar ctrl + c / crtl + v en la consola de bash. De hecho, procure no usuar ctrl + *tecla* en la consola de bash.

---


## Cambios de branch:

#### \*NUNCA usar ninguno de estos comandos con codeblocks abierto. :-1:

#### \*SIEMPRE revisar que los cambios se dieron en los archivos. :+1:

1. Una vez que se esté en la carpeta **TP_Integrador**, darle **click derecho** y clikear la opción **git bash here**.
   #### \*SIEMPRE arrancar tirando el comando `git branch` para ver los *branches* disponibles y el _branch_ actual. :+1:

2. Elegir entre:
  - Crear un nuevo _branch_.
  - Cambiar de _branch_ actual.
  - Borrar _branch_.

  **\* Nota:** `<nombre>` refiere al nombre del _branch_ en cuestión :exclamation:

  #### Crear un nuevo _branch_:

  El comando a utilizar en este caso es `git checkout -b <nombre>`.

  Si se desea utilizar un _branch_ de github, hay que fijarse que coincida el nombre con el _branch_ de github.

  Una vez creado el _branch_, git va a pararse automáticamente al nuevo _branch_.

  **\* Nota:** Cuando se crea un nuevo _branch_, los archivos que van a figurar allí serán los mismos y estarán en el mismo estado que los del _branch_ donde se estaba cuando se creó el nuevo :exclamation:

  #### Cambiar de _branch_ actual:

  Utilizar el comando `git branch` para saber en que _branch_ se encuentra el repositorio actualmente.

  En caso de no estar en el _branch_ deseado, utilizar el comando `git checkout <nombre>` para pasar a tener ese _branch_.

  **\*Nota:** Cuando se crea/cambia de _branch_, los archivos deberían de modificarse automáticamente. En caso de que no ocurra, ver la **sección de problemas comunes** :exclamation:

  #### Borrar _branch_:

  Para borrar un _branch_ primero hay que asegurarse de no encontrarse en el _branch_ que se desea eliminar (ver cambiar de branch).

  Una vez que se encuentra en otro _branch_, utilizar el comando `git branch -D <nombre>`. Esto borrará el _branch_ especificado.

  ### Traer archivos desde **github** al _branch_:

  Se debe de estar en un _branch_ del mismo nombre del que queremos traer los archivos. Una vez allí utilizar el comando `git pull origin <nombre>` para traer los archivos de github al _branch_.

---


## Archivos:

Una vez modificado cualquier archivo git considerará que el _branch_ tiene modificaciones.

Puede utilizarse el comando `git status` para ver aquellos archivos que han sido modificados.

**\*A veces es posible que no se permita cambiar de _branch_ cuando ser realizaron ciertas modificaciones.**

---


## Commits:

Para actualizar los archivos modificados en github (y/o en su repositorio local), deben seguirse los siguientes pasos:

1. Utilizar el comando `git status` para ver qué archivos han sido modificados así como el nombre del _branch_ actual.

2. Utilizar el comando `git add <archivo>` para **agregar el archivo modificado** o `git add .` para agregar **TODOS** los archivos **modificados**.
Estos archivos serán agregados al _staging_ (o _actualización_ del repositorio local) y por ende estarán listos para el _commit_.

3. Utilizar el comando `git commit -m <mensaje>` para hacer el _commit_ en el repositorio local.

4. Para hacer que el _commit_ ocurra en github, es necesario utilizar el comando `git push origin <nombre>.`

 **\*Nota** `<archivo>` refiere al nombre del archivo (exactamente igual a como aparece cuando se corre `git status`) :exclamation:

**\*Nota 2** `<mensaje>` refiere al mensaje que figurará una vez que se suba el archivo como _commit_ :exclamation:

**\*Nota 3** `<nombre>` refiere al nombre del _branch_ en la que va a hacerse el commit. Este se conoce al utilizar el comando `git status` :exclamation:

---


## Merge:
### \*SIEMPRE revisar que **base** y **compare** sean los _branches_ correspondientes.

Una vez se considere que los archivos en un _branch_ en **github** ya están listos para ser integrados al **_branch_ principal** del ejercicio, se debe ir al repositorio en **github** y (en la sección _branches_ en el _branch_ que se desea integrar) se clickea el botón _New pull request_.

**\*Nota** _Merge_ sirve para combinar dos _branches_ en una único _branch_.

#### Detalles del _Pull Request_:

Al generar un _Pull Request_, se habilita para hacer _Merge_. Primero debe seleccionarse la **base** (es decir, en qué _branch_ quedará todo el código una vez que se combinen). Por defecto al crearse el _Pull Request_ desde el _branch_ que queremos combinar, el **compare** (qué _branch_ va a combinarse) será el _branch_ en el cual clickeamos _New pull request_.

El _pull request_ estará sujeto a review y necesitará ser autorizado por quién sea dueñ@ del repositorio.

Una vez aprobado, el botón de _Merge_ estará disponible y al presionarlo se combinarán ambos _branches_.

---


## Importante:

1. Comandos a utilizar seguido:

  - `git branch` (ver el listado de _branches_ así como el _branch_ actual) :eyes:.

  - `git status` (ver el listado de archivos modificados así como el _branch_ actual) :eyes:.

2. Buenas prácticas:

  - Mensajes claros en los _commits_ y en los _pull request_ :+1:.

  - Nombres claros en los _branches_ :mag:.


3. Siempre a tener en cuenta:

  - `git checkout -b <nombre>` siempre genera el nuevo _branch_ a partir de los archivos del _branch_ en la cuál se estaba antes de utilizar el comando :cd:.

  - Mantener el repositorio lo más actualizado posible así es más fácil trabajar entre varias personas el código :wink:.

  - Proveer feedback en los reviews hechos a los _pull request_ así como en los issues :muscle:.

---


## Problemas:
| **Lista de problemas comunes**                                                                          |
| ------------------------------------------------------------------------------------------------------- |
| 1. [**Cambiar de _branch_ no modifica los archivos**](#1-cambios-de-branch-sin-modificación-del-código) |
| 2. [**No me permite cambiar de _branch_**](#2-no-permite-el-cambio-de-branch)                           |
| 3. [**Volver para atrás**](#3-deshacer-cambios)                                                         |
| 4. [**Modificar el mensaje del _commit_**](#4-editar-mensaje-del-commit)                                       |

#### 1. Cambios de _branch_ sin modificación del código:

  - _Mi código no se actualiza/modifica cuando cambio de branch!_

    #### Las posibles causas son las siguientes:
    1. Un programa tiene abierto el archivo que está siendo editado y no tiene soporte de git. Esto está generando problemas ante un cambio de _branch_.
    2. Previamente tener abierto el archivo sin guardar en un programa que no soporte git y pese a que los archivos se modifican, esto no se verá hasta que se vuelvan a abrir (**Y en ese caso guardar probablemente sobreescriba los archivos**).

    #### Las posibles soluciones:
    - Una vez cerrados los programas que ocasionan conflicto, volver a cambiar de _branch_ (cambiar a otro y volver al deseado).
    - Intentar nuevamente todo el proceso previo a abrir los programas.

#### 2. No permite el cambio de _branch_:

  - _Me salta un error por consola al querer cambiar de branch!_

    #### Las posibles causas son las siguientes:
    1. Hay un conflicto de archivos que se han creado y que no se les ha hecho _commit_ o un archivo que debería de existir en el _branch_ al que quiero.
    2. El _branch_ al que se desea cambiar no existe.

    #### Las posibles soluciones:
    1. En caso de ser un archivo trivial el quue sobra, eliminarlo. Caso contrario crear un archivo con el mismo nombre y extensión que el que fue eliminado (ocupando temporalmente el lugar, puede ser eliminado luego).
    2. Crear el _branch_.

#### 3. Deshacer cambios:

  - _Quiero volver atrás todo a como estaba antes!_

    #### Cómo hacerlo?

    Para saber a donde se desea volver, es necesario usar el comando `git reflog` el cuál muestra todo lo que se hizo en git en todos los branches.

    Cada branch tiene un index `HEAD@{<índice>}`.

    Luego utilizar el comando `git reset HEAD@{<índice>}`. Esto devolverá todo al estado de ese índice.

#### 4. Editar mensaje del _commit_:

  - _Hice el commit y quiero reeditar el mensaje!_

    #### Cómo hacerlo?

    Utilizar el comando `git commit --amend` y se abrirá una ventana donde se podrá editar el mensaje del _commit_.

---


## Resumen:

1. Clonar el repositorio (desde **github**):

    En la carpeta que se desea clonar el repositorio utilizar  el comando `git clone <url del repositorio>`

2. Crear/cambiar/borrar _branch_:

    En la carpeta del repositorio:

    Listar los _branches_ actuales: `git branch`
    - Para crear un _branch_: `git checkout -b <nombre>`
    - Para cambiar de _branch_: `git checkout <nombre>`
    - Para borrar un _branch_: `git branch -D <nombre>`

3. Traer los archivos desde un _branch_ de **github** a uno local:

    En un branch del mismo nombre, utilizar el comando: `git pull origin <nombre>`.

4. Estado de los archivos en el _branch_:

    Para ver qué archivos han sufrido modificaciones: `git status`.

5. Preparar archivos para _commit_ (_staging_):

    Correr `git status` para ver aquellos archivos que han sido modificados. Luego:

    - `git add <archivo>` para añadir el archivo específico al _staging_.
    - `git add .` para añadir todos los archivos modificados al _staging_.

6. _Commit_:

    Hacer un commit en el repositorio (una vez hecho el _staging_): `git commit -m <mensaje>`.

7. A **github**:

    Parado sobre el _branch_ que se desea llevar al repositorio en **github** (una vez ya hecho el _commit_): `git push origin <nombre>`.

8. Cómo hacer _Pull Request_ en **github**:

    Ir a la sección _branches_. Seleccionar el _branch_ **en la que se desea combinar el código** modificado como el  _branch_ que figura en el selector que dice _base_. El _branch_ que tiene el código modificado deberá figurar como seleccionada en el selector que dice _compare_.

    Detallar en el mensaje los cambios hechos y presionar en _create new pull request_.

---


## Fotos y ejemplos:
