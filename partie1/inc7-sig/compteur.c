struct gros_compteur
{
    uint32_t grand ;
    uint32_t tresgrand ;
} c = {0, 0} ;

void incrementer (void)
{
    if (c.grand == UINT32_MAX)
    {
	c.grand = 0 ;
	c.tresgrand++ ;
    }
    else c.grand++ ;
}
