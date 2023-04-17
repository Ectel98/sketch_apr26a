#include "fir_filter.h"



double fir_filter_r(double in,double *coef,int n,double *history) { //Paul Embree - C Algorithms for Real-Time DSP 

  double *hist_ptr,*hist1_ptr,*coef_ptr;
  double out;

  hist_ptr = history;
  hist1_ptr = hist_ptr; //storico valori
  coef_ptr = coef + n - 1; //Punto sull'ultimo coefficente

  out = *hist_ptr++ * (*coef_ptr--);
  for (int i = 2; i<n;i++) {
    *hist1_ptr++ = *hist_ptr; //shifta la history
    out += (*hist_ptr++) * (*coef_ptr--);
  }
  out += in * (*coef_ptr);
  *hist1_ptr = in;        //aggiunge l'ultimo valore 

  return(out);
  
}

void inizializate_mw() {

  for (static int i = 0; i<75;i++)
    coef_mw[i] = 0.013333;
    
}

double low_pass_filter(double value){
  return fir_filter_r(value,coef_low_pass,n_pb_coef_low_pass,hist_low_pass);
}

double high_pass_filter(double value){
  return fir_filter_r(value,coef_high_pass,n_pb_coef_high_pass,hist_high_pass);
}


double mowing_windows_average_filter(double value) {

  inizializate_mw();

  return fir_filter_r(value,coef_mw,n_pb_coef_m_w,hist_mw);

  
}
