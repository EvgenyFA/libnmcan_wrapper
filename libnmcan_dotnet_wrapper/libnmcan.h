/**	@file libnmcan.h
  *	@brief ������������ ����. ������� ����������
  */

#pragma once

#include "pch.h"
#define LIBRARY_VERSION 3.1.0


  /**
  * @brief ��������� ������ ��������� (CAN)
  *
  * @return ��������� �� ��������� can_device_list �� ������� ���������
  */
CAN_device_list* CAN_enumerate();
/**
* @brief ������������ ������ ��������� can_device_list
* @param devices ��������f can_device_list
*/
VOID CAN_enumerate_free(CAN_device_list* devices);

/**
* @brief �������� ����������
*
* @param can ��������� �� ��������� can_device_info
* @return ����� ���������� ��� NULL, ���� ��������� ������
*/
HANDLE CAN_open_device(CAN_device_info* can);

/**
* @brief ������ �������� ����������
*
* @param can ��������� �� ����� ����������
* @param bar_addr �����
* @param pbuf ��������� �� UINT32, ���� ����� �������� ���������� ��������
* @return ��� ������ ��� 0 � ������ ������
*/
UINT32 CAN_read_bar(HANDLE* can, UINT32 bar_addr, UINT32* pbuf);

/**
* @brief ������ �������� ����������
*
* @param can ��������� �� ����� ����������
* @param bar_addr �����
* @param pbuf ��������� �� UINT32, ������ ����� ��������� ���������� ��������
* @return ��� ������ ��� 0 � ������ ������
*/
UINT32 CAN_write_bar(HANDLE* can, UINT32 bar_addr, UINT32* pbuf);

/**
* @brief ������ ������ ����������� CAN
*
* @param can ��������� �� ����� ����������
* @param can_addr ����� ��������
* @param channel ����� ������
* @param pbuf ��������� �� ������� ���������� ����� ���� ����� �������� ���������� ������
* @param size ���������� ���� ��� ������
* @return ��� ������ ��� 0 � ������ ������
*/
UINT32 CAN_read_can(HANDLE* can, UINT32 can_addr, UINT8 channel, UINT8* pbuf, UINT8 size);
/**
* @brief ������ ������ ����������� CAN
*
* @param can ��������� �� ����� ����������
* @param can_addr ����� ��������
* @param channel ����� ������
* @param pbuf ��������� �� ����� � ������� ��� ������
* @param size ���������� ���� ��� ������
* @return ��� ������ ��� 0 � ������ ������
*/
UINT32 CAN_write_can(HANDLE* can, UINT32 can_addr, UINT8 channel, UINT8* pbuf, UINT8 size);
/**
* @brief ����������� ���� � �������� ����������� CAN
*
* @param can ��������� �� ����� ����������
* @param can_addr ����� ������� �����
* @param channel ����� ������
* @param data ������ ��� ������
* @param mask �����
* @return ��� ������ ��� 0 � ������ ������
*/
UINT32 CAN_modify_can(HANDLE* can, UINT32 can_addr, UINT8 channel, UINT8 data, UINT8 mask);

/**
* @brief ��������� ������ �� ����������
*
* @param can ��������� �� ����� ����������
* @param pdevinfo ��������� �� ��������� can_DEVINFO ���� ����� �������� ������
* @return ��� ������ ��� 0 � ������ ������
*/
UINT32 CAN_device_version(HANDLE* can, CAN_DEVINFO* pdevinfo);

/**
* @brief ��������� ������ � ������ ��������
*
* @param can ��������� �� ����� ����������
* @param pdevinfo ��������� �� ��������� can_DEVINFO ���� ����� �������� ������
* @return ��� ������ ��� 0 � ������ ������
*/
UINT32 CAN_driver_version(HANDLE* can, CAN_DRVINFO* pdevinfo);

/**
* @brief ������ �� ������ DMA
*
* @param can ��������� �� ����� ����������
* @param channel �����
* @param count ������������ ���������� ������� ������
* @param dmabuf ����� ��������� �� ������ DMA_SLOT_can, ���� ����� �������� ������
* @param timeout ������� �������� � ������ �������������� ���������� ������ � ������ dma
* @return ��� ������ ��� 0 � ������ ������
*/
UINT32 CAN_read_dma(HANDLE* can, UINT8 channel, UINT32 count, DMA_SLOT_CAN** dmabuf, UINT32 timeout);

/**
* @brief ������ � ����� ��������
*
* @param can ��������� �� ����� ����������
* @param channel �����
* @param nbuf ����� ������
* @param prio ���������
* @param timeout ������� ��������
* @param sid ����������� �������������
* @param eid ����������� �������������
* @param pdata ��������� �� ����� � �������
* @param datasize ���������� ������
* @param autorts ���������� ���� ���������� � �������� �� ���������� ������ � �����
* @return ��� ������ ��� 0 � ������ ������
*/
UINT32 CAN_write_txbuf(HANDLE* can, UINT8 channel, UINT8 nbuf, UINT8 prio, UINT32 timeout, UINT32 sid, UINT32 eid, UINT8* pdata, UINT32 datasize, BOOLEAN autorts);
/**
* @brief �������� ������ �� ������ �������� (��������� ����� ���������� � ��������)
*
* @param can ��������� �� ����� ����������
* @param channel �����
* @param nbuf ����� ������
* @return ��� ������ ��� 0 � ������ ������
*/
UINT32 CAN_send_data_now(HANDLE* can, UINT8 channel, UINT8 nbuf);

/**
* @brief ��������� ����������� ������������ �������� TXBnCTRL
*
* @param can ��������� �� ����� ����������
* @param channel �����
* @param nbuf ����� ������
* @param txbnctrl ��������� �� ����������, ���� ����� �������� ���������� �������� txb_ctrl ��� ���������� ������
* @return ��� ������ ��� 0 � ������ ������
*/
UINT32 CAN_check_tx(HANDLE* can, UINT8 channel, UINT8 nbuf, UINT8* txbnctrl);
/**
* @brief �������� �������� �� ������
*
* @param can ��������� �� ����� ����������
* @param channel �����
* @param nbuf ����� ������
* @param timeout ������� �������� � ��
* @return ��� ������ ��� 0 � ������ ������
*/
UINT32 CAN_wait_tx(HANDLE* can, UINT8 channel, UINT8 nbuf, UINT32 timeout);
/**
* @brief ����� ����� ���������� � �������� ��� ���������� ������
*
* @param can ��������� �� ����� ����������
* @param channel �����
* @param nbuf ����� ������
* @return ��� ������ ��� 0 � ������ ������
*/
UINT32 CAN_remove_txreq(HANDLE* can, UINT8 channel, UINT8 nbuf);

/**
* @brief ������ ���� �������� �������
*
* @param can ��������� �� ����� ����������
* @param channel �����
* @return ��� ������ ��� 0 � ������ ������
*/
UINT32 CAN_abat(HANDLE* can, UINT8 channel);

/**
* @brief ����� ����������
*
* @param can ��������� �� ����� ����������
* @return ��� ������ ��� 0 � ������ ������
*/
UINT32 CAN_reset_device(HANDLE* can);
/**
* @brief ����� ����������� CAN
*
* @param can ��������� �� ����� ����������
* @param channel ����� ������ (�����������)
* @return ��� ������ ��� 0 � ������ ������
*/
UINT32 CAN_reset_channel(HANDLE* can, UINT8 channel);

/**
* @brief ��������� ������ ������ ����������� CAN
*
* @param can ��������� �� ����� ����������
* @param channel ����� ������ (�����������)
* @param mode ����� ������
* @return ��� ������ ��� 0 � ������ ������
*/
UINT32 CAN_set_mode(HANDLE* can, UINT8 channel, CAN_MODE mode);
/**
* @brief ������ ������ ������ ����������� CAN
*
* @param can ��������� �� ����� ����������
* @param channel ����� ������ (�����������)
* @param mode ��������� �� ���������� ���� ����� ������� ������� ����� ������
* @return ��� ������ ��� 0 � ������ ������
*/
UINT32 CAN_get_mode(HANDLE* can, UINT8 channel, CAN_MODE* mode);

/**
* @brief ��������� �������� ������ ����������� CAN
*
* @param can ��������� �� ����� ����������
* @param channel ����� ������ (�����������)
* @param speed �������� ��������
* @return ��� ������ ��� 0 � ������ ������
*/
UINT32 CAN_set_speed(HANDLE* can, UINT8 channel, UINT32 speed);
/**
* @brief ������ ��������� �������� ������ ����������� CAN (��. ����������� �� ���������������� ������ can)
*
* @param can ��������� �� ����� ����������
* @param channel ����� ������ (�����������)
* @param speed �� ������������
* @param params ��������� �� ��������� ��������
* @return ��� ������ ��� 0 � ������ ������
*/
UINT32 CAN_set_speed_params(HANDLE* can, UINT8 channel, UINT32* speed, UINT8* params);
/**
* @brief ��������� �������� ������ ����������� CAN (��. ����������� �� ���������������� ������ can)
*
* @param can ��������� �� ����� ����������
* @param channel ����� ������ (�����������)
* @param speed ��������� �� ���������� ���� ����� �������� ����������� ��������
* @param params ��������� �� ������ ���� ����� �������� ��������� ��������
* @return ��� ������ ��� 0 � ������ ������
*/
UINT32 CAN_get_speed(HANDLE* can, UINT8 channel, UINT32* speed, UINT8* params);

/**
* @brief ��������� DMA
*
* @param can ��������� �� ����� ����������
* @return ��� ������ ��� 0 � ������ ������
*/
UINT32 CAN_dma_enable(HANDLE* can);
/**
* @brief ���������� DMA
*
* @param can ��������� �� ����� ����������
* @return ��� ������ ��� 0 � ������ ������
*/
UINT32 CAN_dma_disable(HANDLE* can);


/**
* @brief ���������/���������� ������ oneshot
*
* @param can ��������� �� ����� ����������
* @param channel ����� ������ (�����������)
* @param oneshot 1 ��������, 0 ���������
* @return ��� ������ ��� 0 � ������ ������
*/
UINT32 CAN_set_oneshot(HANDLE* can, UINT8 channel, UINT8 oneshot);
/**
* @brief ��������� ������ CAN
*
* @param can ��������� �� ����� ����������
* @param channel ����� ������ (�����������)
* @param errorinfo ��������� �� ��������� CAN_ERROR_INFO ���� ����� �������� ������ �� �������
* @return ��� ������ ��� 0 � ������ ������
*/
UINT32 CAN_get_errors(HANDLE* can, UINT8 channel, CAN_ERROR_INFO* errorinfo);
/**
* @brief ��������� ����� �����
*
* @param can ��������� �� ����� ����������
* @param channel ����� ������ (�����������)
* @param filter ����� ������
* @param ident ������������ ����������� �������������
* @param id_filter �������� �������
* @param id_mask �������� �����
* @param rxb ����� ������ �������
* @return ��� ������ ��� 0 � ������ ������
*/
UINT32 CAN_set_masks(HANDLE* can, UINT8 channel, UINT8 filter, UINT8 ident, UINT32 id_filter, UINT32 id_mask, UINT8 rxb);

/**
* @brief ��������� �������� ����������� � ������������� �������.
*
* @param can ��������� �� ����� ����������
* @param channel ����� ������ (�����������)
* @param absolute �������� ����������� �������
* @param interval �������� ������������� �������
* @return ��� ������ ��� 0 � ������ ������
*/
UINT32 CAN_set_timeouts(HANDLE* can, UINT8 channel, UINT32 absolute, UINT32 interval);

/**
* @brief ��������� ������ �������� ����������� CAN (�������/FIFO)
*
* @param can ��������� �� ����� ����������
* @param channel ����� ������ (�����������)
* @param mode ����� ������
* @return ��� ������ ��� 0 � ������ ������
*/
UINT32 CAN_set_send_mode(HANDLE* can, UINT8 channel, CTRL_MODE mode);

/**
* @brief ��������� ���������� ������� � ������ FIFO
*
* @param can ��������� �� ����� ����������
* @param channel ����� ������ (�����������)
* @param isHPFIFO ���� ������������� ������������������� FIFO
* @param count ��������� �� ���������� ���� ����� �������� ���������� �������
* @return ��� ������ ��� 0 � ������ ������
*/
UINT32 CAN_get_fifo_count(HANDLE* can, UINT8 channel, UINT8 isHPFIFO, UINT8* count);

/**
* @brief ������ ������ � ����� FIFO
*
* @param can ��������� �� ����� ����������
* @param channel ����� ������ (�����������)
* @param sid ����������� �������������
* @param eid ����������� �������������
* @param data ��������� �� ����� � �������
* @param size ������ ������ � �������
* @param msgid id ���������
* @param isHPFIFO ���� ������������� ������������������� FIFO
* @return ��� ������ ��� 0 � ������ ������
*/
UINT32 CAN_write_data_to_fifo(HANDLE* can, UINT8 channel, UINT32 sid, UINT32 eid, UINT8* data, UINT32 size, UINT8 msgid, UINT8 isHPFIFO);

/**
* @brief ���������� ������ TX_Pause
*
* @param can ��������� �� ����� ����������
* @param channel ����� ������ (�����������)
* @param txpause �������� ���� TX_Pause  �������� REG_CANn_FIFO_CONSTAT
* @param isHPFIFO ���� ������������� ������������������� FIFO
* @return ��� ������ ��� 0 � ������ ������
*/
UINT32 CAN_set_tx_pause(HANDLE* can, UINT8 channel, UINT32 txpause, UINT8 isHPFIFO);

/**
* @brief ��������� ��������� ��� FIFO
*
* @param can ��������� �� ����� ����������
* @param channel ����� ������ (�����������)
* @param timeout �������
* @param isHPFIFO ���� ������������� ������������������� FIFO
* @return ��� ������ ��� 0 � ������ ������
*/
UINT32 CAN_set_fifo_timeout(HANDLE* can, UINT8 channel, UINT32 timeout, UINT8 isHPFIFO);

/**
* @brief ������������� ������ ������
*/
void CAN_decode_buf(DMA_SLOT_CAN* dma, UINT32* nbuf, UINT8* channel, UINT32* tmr_epoch, UINT32* tmr_ntu, UINT32* tmr_div, UINT32* sid, UINT32* eid, UINT8* data, UINT8* datasize);

/**
* @brief ������������� ����������� � ���������� ������ (������ �����, ����� ������������� ����� ������� � native ������ � ��������� 1000)
*
* @param can ��������� �� ����� ����������
*/
VOID CAN_d_enable(HANDLE* can);

/**
* @brief ��������� ��������� ����������
*
* @param can ��������� �� ����� ����������
* @param channel ����� ������
* @param reset ����� ��������� - �������� �� ���� �������� ���������� ��������
* @param canstat ��������� �� ��������� CAN_CANXSTAT, ���� ����� �������� ������
* @return ��� ������ ��� 0 � ������ ������
*/
UINT32 CAN_get_stats(HANDLE* can, UINT8 channel, UINT8 reset, CAN_CANXSTAT* canstat);