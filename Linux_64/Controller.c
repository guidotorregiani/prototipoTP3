#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int retorno=-1;
    if(pArrayListEmployee!=NULL)
    {
        pFile = fopen(path,"r");
        if(pFile!=NULL)
        {
            parser_EmployeeFromText(pFile , pArrayListEmployee);
            fclose(pFile);
            retorno=0;
        }
    }
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int retorno=-1;

    pFile=fopen(path,"rb");
    if(pFile!=NULL)
    {
        parser_EmployeeFromBinary(pFile,pArrayListEmployee);
        fclose(pFile);
        retorno=0;
    }
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pE;
    int auxId;
    int auxSueldo;
    int auxHoras;
    char auxNombre[4096];
    int size;
    int i;

    if(pArrayListEmployee!=NULL)
    {
        size=ll_len(pArrayListEmployee);
        for(i=0;i<size;i++)
        {
            pE=ll_get(pArrayListEmployee,i);
            employee_getId(pE,&auxId);
            employee_getNombre(pE,auxNombre);
            employee_getSueldo(pE,&auxSueldo);
            employee_getHorasTrabajadas(pE,&auxHoras);
            if(pE!=NULL)
            {
                printf("%d,%s,%d,%d\n",auxId,
                                        auxNombre,
                                        auxSueldo,
                                        auxHoras);
            }
        }
    }
   return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    Employee* pE;
    int auxId;
    int auxSueldo;
    int auxHoras;
    char auxNombre[4096];
    int size;
    int i;

    FILE* fp=fopen(path,"w+");
    if(fp!=NULL && pArrayListEmployee!=NULL)
    {
        fprintf(fp,"id,nombre,horasTrabajadas,sueldo\n");

        size=ll_len(pArrayListEmployee);

        for(i=0;i<size;i++)
        {
            pE=ll_get(pArrayListEmployee,i);
            employee_getId(pE,&auxId);
            employee_getNombre(pE,auxNombre);
            employee_getSueldo(pE,&auxSueldo);
            employee_getHorasTrabajadas(pE,&auxHoras);
            if(pE!=NULL)
            {
                fprintf(fp,"%d,%s,%d,%d\n",auxId,
                                        auxNombre,
                                        auxSueldo,
                                        auxHoras);
            }
        }
        fclose(fp);
        return 0;
    }
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    Employee* pE;
    int size;
    int i;

    FILE* fp=fopen(path,"w+b");
    if(fp!=NULL)
    {
        size=ll_len(pArrayListEmployee);

        for(i=0;i<size;i++)
        {
            pE=ll_get(pArrayListEmployee,i);
            fwrite(pE,sizeof(Employee),1,fp);
        }

        fclose(fp);
        return 0;
    }

    return 1;
}

