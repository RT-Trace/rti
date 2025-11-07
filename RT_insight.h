#ifndef __RT_INSIGHT_H__
#define __RT_INSIGHT_H__

#include "RT_LOG_Print.h"
#include "RT_insight_config.h"
#include "RT_tunnel.h"
#include "rtthread.h"
#include <rthw.h>


/* ---------------- Insight Data Structure ---------------- */
/**
 * @struct RT_insight_info
 * @brief Structure representing an insight event or trace information.
 */
typedef struct _RT_insight_info
{
    uint32_t Frame_Header;     /**< Frame header, 4 bytes */
    uint32_t ID;               /**< Event ID, 4 bytes */
    uint32_t Track_Type;       /**< Track type, 4 bytes */
    uint32_t Time_Stamp_ns_lo; /**< Lower 32 bits of timestamp in nanoseconds */
    uint32_t Time_Stamp_ns_hi; /**< Higher 32 bits of timestamp in nanoseconds */
} RT_insight_info;

/* ---------------- RT-Thread Hook Functions ---------------- */
/**
 * @brief Scheduler hook: called when switching from one thread to another.
 *
 * @param[in] from_thread  Thread being switched out
 * @param[in] to_thread    Thread being switched in
 */
static void rt_view_scheduler_hook(rt_thread_t from_thread, rt_thread_t to_thread);

/**
 * @brief Hook function called when a thread is resumed.
 *
 * @param[in] thread  Thread being resumed
 */
static void rt_view_thread_resume_hook(rt_thread_t thread);

/**
 * @brief Hook function called when a thread is suspended.
 *
 * @param[in] thread  Thread being suspended
 */
static void rt_view_thread_suspend_hook(rt_thread_t thread);

/**
 * @brief Hook function called when entering an ISR.
 */
static void rt_view_ISR_enter_hook(void);

/**
 * @brief Hook function called when leaving an ISR.
 */
static void rt_view_ISR_leave_hook(void);

/**
 * @brief Hook function called when an RTOS object is successfully taken.
 *
 * @param[in] object  Pointer to the RTOS object
 */
static void rt_view_object_take_hook(struct rt_object *object);

/**
 * @brief Hook function called when trying to take an RTOS object (non-blocking).
 *
 * @param[in] object  Pointer to the RTOS object
 */
static void rt_view_object_trytake_hook(struct rt_object *object);

/**
 * @brief Hook function called when an RTOS object is released.
 *
 * @param[in] object  Pointer to the RTOS object
 */
static void rt_view_object_relase_hook(struct rt_object *object);

/**
 * @brief Hook function called when a timer enters (callback execution start).
 *
 * @param[in] t  Timer instance
 */
static void rt_view_timer_enter_hook(rt_timer_t t);

/**
 * @brief Hook function called when a timer exits (callback execution end).
 *
 * @param[in] t  Timer instance
 */
static void rt_view_timer_exit_hook(rt_timer_t t);

/* ---------------- Insight Utility Functions ---------------- */
/**
 * @brief Get current time in nanoseconds.
 *
 * @retval uint64_t  Current timestamp in nanoseconds
 */
static uint64_t Get_Time_Stamp_ns(uint8_t add_flag);

/**
 * @brief Record an insight event.
 *
 * @param[in] ID          Event ID
 * @param[in] track_type  Track type
 */
static void Event_Record(uint32_t ID, uint32_t track_type);

/* ---------------- Insight Initialization ---------------- */
/**
 * @brief Initialize the RT Insight module.
 *
 * @retval int  0 on success, negative value on error
 */
int RT_Insight_Init(void);

#endif // __RT_INSIGHT_H__
