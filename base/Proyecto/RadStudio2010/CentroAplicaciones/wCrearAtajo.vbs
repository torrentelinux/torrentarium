R e m   w C r e a r A t a j o . v b s  
 R e m   O c t u l i o   B i l e t � n   - -   t o r r e n t e l i n u x @ g m a i l . c o m   - -   M a r z o   d e   2 0 2 1 .  
 R e m   C r e a   u n   a t a j o   o   a c c e s o   d i r e c t o   e n   e l   E s c r i t o r i o   d e   W i n d o w s .  
 R e m   U s o :  
 R e m   w C r e a r A t a j o   M i A p l i c . l n k   C : \ b a s e \ a p l i c a c i o n e s \ M i A p l i c \ M i A p l i c . e x e   C : \ b a s e \ a p l i c a c i o n e s \ M i A p l i c \   " M i   a p l i c a c i � n   p r e f e r i d a . "  
 R e m   R e f e r e n c i a s :  
 R e m   I D E   p a r a   V B S c r i p t   * * *   h t t p s : / / w w w . v b s e d i t . c o m /  
 R e m   h t t p s : / / w w w . h e e l p b o o k . n e t / 2 0 1 2 / v i s u a l - b a s i c - d o s - a d d - t o - f a v o r i t e s - i n - i n t e r n e t - e x p l o r e r - w i t h - b a t c h - f i l e /  
 R e m   h t t p s : / / s t a c k o v e r f l o w . c o m / q u e s t i o n s / 2 4 6 9 7 5 4 / u s i n g - c o m m a n d - l i n e - a r g u m e n t s - i n - v b s c r i p t  
 R e m   h t t p s : / / w w w . t u t o r i a l s p o i n t . c o m / v b s c r i p t / v b s c r i p t _ d i a l o g _ b o x e s . h t m  
 R e m   h t t p s : / / w w w . v b s e d i t . c o m / h t m l / 5 c e 0 4 e 4 b - 8 7 1 a - 4 3 7 8 - a 1 9 2 - c a a 6 4 4 b d 9 c 5 5 . a s p  
  
 S e t   W s h S h e l l   =   C r e a t e O b j e c t ( " W S c r i p t . S h e l l " )  
 s t r D e s k t o p P a t h   =   W s h S h e l l . S p e c i a l F o l d e r s ( " D e s k t o p " )  
 s t a t u s   =   0  
  
 I f   W s c r i p t . A r g u m e n t s . C o u n t   =   0   t h e n    
         M s g B o x   " N o   h a y   a r g u m e n t o s   ! ! ! " ,   v b C r i t i c a l ,   " E r r o r "  
         s t a t u s   =   1  
 E n d   I f  
  
 I f   W s c r i p t . A r g u m e n t s . C o u n t   >   4   t h e n    
         M s g B o x   " D e m a s i a d o s   a r g u m e n t o s   ! ! ! " ,   v b C r i t i c a l ,   " E r r o r "  
         s t a t u s   =   1  
 E n d   I f  
  
 I f   W s c r i p t . A r g u m e n t s . C o u n t   <   4   t h e n    
         M s g B o x   " I n s u f i c i e n t e s   a r g u m e n t o s   ! ! ! " ,   v b C r i t i c a l ,   " E r r o r "  
         s t a t u s   =   1  
 E n d   I f  
  
 i f   s t a t u s   =   1   t h e n  
         M s g B o x   " <   U s a r   > "   &   C h r ( 1 3 )   &   C h r ( 1 0 )   &   W S c r i p t . S c r i p t N a m e   & "   < a t a j o . l n k >   < d e s t i n o . e x e >   < i n i c i a r   e n   d i r . >   < c o m e n t a r i o > " ,   v b I n f o r m a t i o n ,   " : : A v i s o : : "  
         W s c r i p t . Q u i t ( s t a t u s )  
 e n d   i f  
  
 ' S e t   o b j S h o r t c u t   =   W s h S h e l l . C r e a t e S h o r t c u t ( s t r D e s k t o p P a t h   &   " \ J D e v e l o p e r . l n k " )  
 S e t   o b j S h o r t c u t   =   W s h S h e l l . C r e a t e S h o r t c u t ( s t r D e s k t o p P a t h   &   " \ "   &   W S c r i p t . A r g u m e n t s . I t e m ( 0 ) )  
  
 ' d e s t i n o :   C : \ b a s e \ a p l i c a c i o n e s \ j d e v e l o p e r \ j d e v e l o p e r . e x e  
 o b j S h o r t c u t . T a r g e t P a t h   =   W S c r i p t . A r g u m e n t s . I t e m ( 1 )  
  
 ' i n i c i a r   e n :   c : \ b a s e \ a p l i c a c i o n e s \ j d e v e l o p e r  
 o b j S h o r t c u t . W o r k i n g D i r e c t o r y   =   W S c r i p t . A r g u m e n t s . I t e m ( 2 )  
  
 ' c o m e n t a r i o :   O r a c l e   J D e v e l o p e r   b � s i c o .  
 o b j S h o r t c u t . D e s c r i p t i o n   =   W S c r i p t . A r g u m e n t s . I t e m ( 3 )  
 o b j S h o r t c u t . W i n d o w S t y l e   =   1  
 o b j S h o r t c u t . S a v e  
  
 M s g B o x   " A t a j o   c r e a d o .   � L i s t o ! " ,   v b I n f o r m a t i o n ,   " : : A v i s o : : "  
 