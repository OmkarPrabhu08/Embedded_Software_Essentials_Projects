////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                         //
//                                                                                                         //
//  @file             project_1.h                                                                          //
//  @author           Omkar Prabhu                                                                         //
//                    Aasheesh Dandupally                                                                  //
//  @brief            Defination file for project_1.c                                                      // 
//                                                                                                         //
//                                                                                                         //
//                                                                                                         //
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _PROJECT_1_H_
#define _PROJECT_1_H_

/**
 * This moves creates two data sets which consists hex and dec numbers and calls test functions  
 *
 * @params nothing
 *         
 *         
 *         
 * @return nothing  
 */
void project_1_report(void);

/**
 * This calls little_to_big and big_to_little functions and test them with inputs passed by project_1
 *
 * @params arr(data source address)
 *                  
 *         
 * @return nothing  
 */
void test_data1(uint32_t * arr);

/**
 * This call itoa and atoi functions and test them with inputs passed by project_1
 *
 * @params data(data source address)
 *         
 *            
 * @return nothing   
 */
void test_data2(int8_t *data);

/**
 * This calls memory functions and test them with inputs passed by project_1
 * 
 *
 * @params src(data source address)
 *         
 *         
 *         
 * @return nothing   
 */
void test_memory(int8_t *data);

#endif /* project_1.h */
