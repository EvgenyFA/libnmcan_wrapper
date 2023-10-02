/**	@file libnmcan.h
  *	@brief Заголовочный файл. Функции библиотеки
  */

#pragma once

#include "pch.h"
#define LIBRARY_VERSION 3.1.0


  /**
  * @brief Получение списка устройств (CAN)
  *
  * @return указатель на структуру can_device_list со списком устройств
  */
CAN_device_list* CAN_enumerate();
/**
* @brief Освобождение памяти структуры can_device_list
* @param devices структурf can_device_list
*/
VOID CAN_enumerate_free(CAN_device_list* devices);

/**
* @brief Открытие устройства
*
* @param can указатель на структуру can_device_info
* @return хэндл устройства или NULL, если произошла ошибка
*/
HANDLE CAN_open_device(CAN_device_info* can);

/**
* @brief Чтение регистра устройства
*
* @param can указатель на хэндл устройства
* @param bar_addr адрес
* @param pbuf указатель на UINT32, куда будет записано содержимое регистра
* @return код ошибки или 0 в случае успеха
*/
UINT32 CAN_read_bar(HANDLE* can, UINT32 bar_addr, UINT32* pbuf);

/**
* @brief Запись регистра устройства
*
* @param can указатель на хэндл устройства
* @param bar_addr адрес
* @param pbuf указатель на UINT32, откуда будет прочитано содержимое регистра
* @return код ошибки или 0 в случае успеха
*/
UINT32 CAN_write_bar(HANDLE* can, UINT32 bar_addr, UINT32* pbuf);

/**
* @brief Чтение памяти контроллера CAN
*
* @param can указатель на хэндл устройства
* @param can_addr адрес регистра
* @param channel номер канала
* @param pbuf указатель на заранее выделенный буфер куда будут записаны полученные данные
* @param size количество байт для чтения
* @return код ошибки или 0 в случае успеха
*/
UINT32 CAN_read_can(HANDLE* can, UINT32 can_addr, UINT8 channel, UINT8* pbuf, UINT8 size);
/**
* @brief Запись памяти контроллера CAN
*
* @param can указатель на хэндл устройства
* @param can_addr адрес регистра
* @param channel номер канала
* @param pbuf указатель на буфер с данными для записи
* @param size количество байт для записи
* @return код ошибки или 0 в случае успеха
*/
UINT32 CAN_write_can(HANDLE* can, UINT32 can_addr, UINT8 channel, UINT8* pbuf, UINT8 size);
/**
* @brief Модификация байт в регистре контроллера CAN
*
* @param can указатель на хэндл устройства
* @param can_addr адрес первого байта
* @param channel номер канала
* @param data данные для записи
* @param mask маска
* @return код ошибки или 0 в случае успеха
*/
UINT32 CAN_modify_can(HANDLE* can, UINT32 can_addr, UINT8 channel, UINT8 data, UINT8 mask);

/**
* @brief Получение данных об устройстве
*
* @param can указатель на хэндл устройства
* @param pdevinfo указатель на структуру can_DEVINFO куда будут записаны данные
* @return код ошибки или 0 в случае успеха
*/
UINT32 CAN_device_version(HANDLE* can, CAN_DEVINFO* pdevinfo);

/**
* @brief Получение данных о версии драйвера
*
* @param can указатель на хэндл устройства
* @param pdevinfo указатель на структуру can_DEVINFO куда будут записаны данные
* @return код ошибки или 0 в случае успеха
*/
UINT32 CAN_driver_version(HANDLE* can, CAN_DRVINFO* pdevinfo);

/**
* @brief Чтение из буфера DMA
*
* @param can указатель на хэндл устройства
* @param channel канал
* @param count максимальное количество пакетов данных
* @param dmabuf адрес указателя на массив DMA_SLOT_can, куда будут записаны данные
* @param timeout таймаут ожидания в случае недостаточного количества данных в буфере dma
* @return код ошибки или 0 в случае успеха
*/
UINT32 CAN_read_dma(HANDLE* can, UINT8 channel, UINT32 count, DMA_SLOT_CAN** dmabuf, UINT32 timeout);

/**
* @brief Запись в буфер передачи
*
* @param can указатель на хэндл устройства
* @param channel канал
* @param nbuf номер буфера
* @param prio приоритет
* @param timeout таймаут отправки
* @param sid стандартный идентификатор
* @param eid расширенный идентификатор
* @param pdata указатель на буфер с данными
* @param datasize количество данных
* @param autorts установить флаг готовности к передачи по завершению записи в буфер
* @return код ошибки или 0 в случае успеха
*/
UINT32 CAN_write_txbuf(HANDLE* can, UINT8 channel, UINT8 nbuf, UINT8 prio, UINT32 timeout, UINT32 sid, UINT32 eid, UINT8* pdata, UINT32 datasize, BOOLEAN autorts);
/**
* @brief Отправка данных из буфера передачи (установка флага готовности к передаче)
*
* @param can указатель на хэндл устройства
* @param channel канал
* @param nbuf номер буфера
* @return код ошибки или 0 в случае успеха
*/
UINT32 CAN_send_data_now(HANDLE* can, UINT8 channel, UINT8 nbuf);

/**
* @brief Получение содержимого управляющего регистра TXBnCTRL
*
* @param can указатель на хэндл устройства
* @param channel канал
* @param nbuf номер буфера
* @param txbnctrl указатель на переменную, куда будет записано содержимое регистра txb_ctrl для выбранного канала
* @return код ошибки или 0 в случае успеха
*/
UINT32 CAN_check_tx(HANDLE* can, UINT8 channel, UINT8 nbuf, UINT8* txbnctrl);
/**
* @brief Ожидание передачи из буфера
*
* @param can указатель на хэндл устройства
* @param channel канал
* @param nbuf номер буфера
* @param timeout таймаут ожидания в мс
* @return код ошибки или 0 в случае успеха
*/
UINT32 CAN_wait_tx(HANDLE* can, UINT8 channel, UINT8 nbuf, UINT32 timeout);
/**
* @brief Сброс флага готовности к передаче для указанного буфера
*
* @param can указатель на хэндл устройства
* @param channel канал
* @param nbuf номер буфера
* @return код ошибки или 0 в случае успеха
*/
UINT32 CAN_remove_txreq(HANDLE* can, UINT8 channel, UINT8 nbuf);

/**
* @brief Отмена всех активных передач
*
* @param can указатель на хэндл устройства
* @param channel канал
* @return код ошибки или 0 в случае успеха
*/
UINT32 CAN_abat(HANDLE* can, UINT8 channel);

/**
* @brief Сброс устройства
*
* @param can указатель на хэндл устройства
* @return код ошибки или 0 в случае успеха
*/
UINT32 CAN_reset_device(HANDLE* can);
/**
* @brief Сброс контроллера CAN
*
* @param can указатель на хэндл устройства
* @param channel номер канала (контроллера)
* @return код ошибки или 0 в случае успеха
*/
UINT32 CAN_reset_channel(HANDLE* can, UINT8 channel);

/**
* @brief Установка режима работы контроллера CAN
*
* @param can указатель на хэндл устройства
* @param channel номер канала (контроллера)
* @param mode режим работы
* @return код ошибки или 0 в случае успеха
*/
UINT32 CAN_set_mode(HANDLE* can, UINT8 channel, CAN_MODE mode);
/**
* @brief Чтение режима работы контроллера CAN
*
* @param can указатель на хэндл устройства
* @param channel номер канала (контроллера)
* @param mode указатель на переменную куда будет записан текущий режим работы
* @return код ошибки или 0 в случае успеха
*/
UINT32 CAN_get_mode(HANDLE* can, UINT8 channel, CAN_MODE* mode);

/**
* @brief Установка скорости работы контроллера CAN
*
* @param can указатель на хэндл устройства
* @param channel номер канала (контроллера)
* @param speed желаемая скорость
* @return код ошибки или 0 в случае успеха
*/
UINT32 CAN_set_speed(HANDLE* can, UINT8 channel, UINT32 speed);
/**
* @brief Ручная установка скорости работы контроллера CAN (см. руководство по программированию модуля can)
*
* @param can указатель на хэндл устройства
* @param channel номер канала (контроллера)
* @param speed не используется
* @param params указатель на параметры скорости
* @return код ошибки или 0 в случае успеха
*/
UINT32 CAN_set_speed_params(HANDLE* can, UINT8 channel, UINT32* speed, UINT8* params);
/**
* @brief Получение скорости работы контроллера CAN (см. руководство по программированию модуля can)
*
* @param can указатель на хэндл устройства
* @param channel номер канала (контроллера)
* @param speed указатель на переменную куда будет записана стандартная скорость
* @param params указатель на массив куда будут записаны параметры скорости
* @return код ошибки или 0 в случае успеха
*/
UINT32 CAN_get_speed(HANDLE* can, UINT8 channel, UINT32* speed, UINT8* params);

/**
* @brief Включение DMA
*
* @param can указатель на хэндл устройства
* @return код ошибки или 0 в случае успеха
*/
UINT32 CAN_dma_enable(HANDLE* can);
/**
* @brief Выключение DMA
*
* @param can указатель на хэндл устройства
* @return код ошибки или 0 в случае успеха
*/
UINT32 CAN_dma_disable(HANDLE* can);


/**
* @brief Включение/выключение режима oneshot
*
* @param can указатель на хэндл устройства
* @param channel номер канала (контроллера)
* @param oneshot 1 включает, 0 выключает
* @return код ошибки или 0 в случае успеха
*/
UINT32 CAN_set_oneshot(HANDLE* can, UINT8 channel, UINT8 oneshot);
/**
* @brief Получение ошибок CAN
*
* @param can указатель на хэндл устройства
* @param channel номер канала (контроллера)
* @param errorinfo указатель на структуру CAN_ERROR_INFO куда будут записаны данные об ошибках
* @return код ошибки или 0 в случае успеха
*/
UINT32 CAN_get_errors(HANDLE* can, UINT8 channel, CAN_ERROR_INFO* errorinfo);
/**
* @brief Установка масок приёма
*
* @param can указатель на хэндл устройства
* @param channel номер канала (контроллера)
* @param filter номер буфера
* @param ident использовать расширенный идентификатор
* @param id_filter значение фильтра
* @param id_mask значение маски
* @param rxb режим работы фильтра
* @return код ошибки или 0 в случае успеха
*/
UINT32 CAN_set_masks(HANDLE* can, UINT8 channel, UINT8 filter, UINT8 ident, UINT32 id_filter, UINT32 id_mask, UINT8 rxb);

/**
* @brief Установка значений абсолютного и интервального таймера.
*
* @param can указатель на хэндл устройства
* @param channel номер канала (контроллера)
* @param absolute значение абсолютного таймера
* @param interval значение интервального таймера
* @return код ошибки или 0 в случае успеха
*/
UINT32 CAN_set_timeouts(HANDLE* can, UINT8 channel, UINT32 absolute, UINT32 interval);

/**
* @brief Установка режима передачи контроллера CAN (обычный/FIFO)
*
* @param can указатель на хэндл устройства
* @param channel номер канала (контроллера)
* @param mode режим работы
* @return код ошибки или 0 в случае успеха
*/
UINT32 CAN_set_send_mode(HANDLE* can, UINT8 channel, CTRL_MODE mode);

/**
* @brief получение количества пакетов в буфере FIFO
*
* @param can указатель на хэндл устройства
* @param channel номер канала (контроллера)
* @param isHPFIFO флаг использования высокоприоритетного FIFO
* @param count указатель на переменную куда будет записано количество пакетов
* @return код ошибки или 0 в случае успеха
*/
UINT32 CAN_get_fifo_count(HANDLE* can, UINT8 channel, UINT8 isHPFIFO, UINT8* count);

/**
* @brief запись пакета в буфер FIFO
*
* @param can указатель на хэндл устройства
* @param channel номер канала (контроллера)
* @param sid стандартный идентификатор
* @param eid расширенный идентификатор
* @param data указатель на буфер с данными
* @param size размер буфера с данными
* @param msgid id сообщения
* @param isHPFIFO флаг использования высокоприоритетного FIFO
* @return код ошибки или 0 в случае успеха
*/
UINT32 CAN_write_data_to_fifo(HANDLE* can, UINT8 channel, UINT32 sid, UINT32 eid, UINT8* data, UINT32 size, UINT8 msgid, UINT8 isHPFIFO);

/**
* @brief Управление флагом TX_Pause
*
* @param can указатель на хэндл устройства
* @param channel номер канала (контроллера)
* @param txpause значение бита TX_Pause  регистра REG_CANn_FIFO_CONSTAT
* @param isHPFIFO флаг использования высокоприоритетного FIFO
* @return код ошибки или 0 в случае успеха
*/
UINT32 CAN_set_tx_pause(HANDLE* can, UINT8 channel, UINT32 txpause, UINT8 isHPFIFO);

/**
* @brief Установка таймаутов для FIFO
*
* @param can указатель на хэндл устройства
* @param channel номер канала (контроллера)
* @param timeout таймаут
* @param isHPFIFO флаг использования высокоприоритетного FIFO
* @return код ошибки или 0 в случае успеха
*/
UINT32 CAN_set_fifo_timeout(HANDLE* can, UINT8 channel, UINT32 timeout, UINT8 isHPFIFO);

/**
* @brief Декодирование пакета данных
*/
void CAN_decode_buf(DMA_SLOT_CAN* dma, UINT32* nbuf, UINT8* channel, UINT32* tmr_epoch, UINT32* tmr_ntu, UINT32* tmr_div, UINT32* sid, UINT32* eid, UINT8* data, UINT8* datasize);

/**
* @brief Инициализация контроллера в отладочном режиме (полный сброс, затем инициализация обоих каналов в native режиме с скоростью 1000)
*
* @param can указатель на хэндл устройства
*/
VOID CAN_d_enable(HANDLE* can);

/**
* @brief Получение счётчиков устройства
*
* @param can указатель на хэндл устройства
* @param channel номер канала
* @param reset сброс счётчиков - отличное от нуля значение сбрасывает счётчики
* @param canstat указатель на структуру CAN_CANXSTAT, куда будут записаны данные
* @return код ошибки или 0 в случае успеха
*/
UINT32 CAN_get_stats(HANDLE* can, UINT8 channel, UINT8 reset, CAN_CANXSTAT* canstat);