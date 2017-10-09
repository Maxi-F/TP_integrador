# Instructivo de pasos a seguir cuando usen GIT en este trabajo:


#### \*SIEMPRE leer la sección 6 antes de trabajar. :smile: :+1:

| **Contenido**                                                     |
| ----------------------------------------------------------------- |
| 1. [**Primera vez clonando archivos desde github**](#primer-clon) |
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

## Primer clon:

#### Ir a la carpeta donde van a guardar los archivos.

1. Darle **click derecho** y clickear la opción **git bash here**.
2. Tipear o copiar y pegar\* el comando `git clone "https://github.com/Maxi-F/TP_Integrador"`
3. Acá se puede proseguir de dos formas distintas:
  - O se cierra la consola, se va a la carpeta TP_Integrador y nuevamente repite el paso 1.
  - Tipear `cd TP_Integrador` en la consola (`cd` significa *change directory*).
4. Ahora se estará en el directorio y el repositorio estará en la *branch* **__master__**.
5. Ver paso siguiente para saber como importar los branches existentes.

\*Recuerde que no funciona usar ctrl + c / crtl + v en la consola de bash. De hecho, procure no usuar ctrl + *tecla* en la consola de bash.

## Cambios de branch:

#### \*NUNCA usar ninguno de estos comandos con codeblocks abierto. :-1:

#### \*SIEMPRE revisar que los cambios se dieron en los archivos. :+1:

1. Una vez que se esté en la carpeta **TP_Integrador**, darle **click derecho** y clikear la opción **git bash here**.
#### \*SIEMPRE arrancar tirando el comando `git branch` para ver las *branch* disponibles y la actual. :+1:

2. Elegir entre:
  - Crear una nueva _branch_.
  - Cambiar de _branch_ actual.
  - Borrar _branch_.

  ** \* Nota: ** `<nombre>` refiere al nombre de la _branch_ en cuestión :exclamation:

  #### Crear una nueva _branch_:

  ** \* Nota: ** Cuando se crea una nueva _branch_, los archivos que van a figurar allí serán los mismos y estarán en el mismo estado que los de la _branch_ donde se estaba cuando se creó la nueva :exclamation:

  El comando a utilizar en este caso es `git checkout -b <nombre>`.

  Si se desea utilizar una _branch_ de github, hay que fijarse que coincida el nombre con la _branch_ de github.

  Una vez creada la _branch_, git va a pararse automáticamente al nueva _branch_.

  #### Cambiar de _branch_ actual:

  ** \* Nota: ** Cuando se crea cambia de _branch_, los archivos deberían de modificarse automáticamente. En caso de que no ocurra, ver la **sección de problemas comunes** :exclamation:

  Utilizar el comando `git branch` para saber en que _branch_ se encuentra el repositorio actualmente.

  En caso de no estar en la _branch_ deseada, utilizar el comando `git checkout <nombre>` para pasar a tener esa _branch_.

  #### Borrar _branch_:

  Para borrar una _branch_ primero hay que asegurarse de no encontrarse en la _branch_ que se desea eliminar (ver cambiar de branch).

  Una vez que se encuentra en otro _branch_, utilizar el comando `git branch -D <nombre>`.

  ### Traer archivos desde **github** a la _branch_:

  Se debe de estar en una _branch_ del mismo nombre de la que queremos traer los archivos. Una vez allí utilizar el comando `git pull origin <nombre>` para traer los archivos de github a la carpeta.


## Archivos:

Una vez modificado cualquier archivo git considerará que la _branch_ tiene modificaciones.

Puede utilizarse el comando `git status` para ver aquellos archivos que han sido modificados (en caso de haber modificado el main y haberlo compilado y corrido, deberían de haber al menos 3 archivos modificados).

** \*A veces es posible que no se permita cambiar de _branch_ cuando ser realizaron ciertas modificaciones.**


## Commits:

#### \*Nota `<archivo>` refiere al nombre del archivo (exactamente igual a como aparece cuando se corre `git status`) :exclamation:

#### \*Nota 2 `<mensaje>` refiere al mensaje que figurará una vez que se suba el archivo como _commit_ :exclamation:

#### \*Nota 3 `<nombre>` refiere al nombre de la _branch_ en la que va a hacerse el commit. Este se conoce al utilizar el comando `git status` :exclamation:

Para actulizar los archivos modificados en github (y/o en su repositorio local), deben seguirse los siguientes pasos:

1. Utilizar el comando `git status` para ver qué archivos han sido modificados así como el nombre de la _branch_ actual.

2. Utilizar el comando `git add <archivo>` para **agregar el archivo modificado** o `git add .` para agregar **TODOS** los archivos **modificados**.
Estos archivos serán agregados al _staging_ (o _actualización_ del repositorio local) y por ende estarán listos para el _commit_.

3. Utilizar el comando `git commit -m <mensaje>` para hacer el _commit_ en el repositorio local.

4. Para hacer que el _commit_ ocurra en github, es necesario utilizar el comando `git push origin <nombre>.`

## Merge:



## Importante:



## Problemas:



## Resumen:



## Fotos y ejemplos:
