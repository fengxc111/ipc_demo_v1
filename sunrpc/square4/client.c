#include    "unpipc.h"
#include    "square.h"

int
main(int argc, char **argv)
{
    CLIENT  *cl;
    square_in   in;
    square_out  out;

    if (argc != 3)
        err_quit("usage: client <hostname> <integer-value>");
    
    cl = Clnt_create(argv[1], SQUARE_PROG, SQUARE_VERS, "tcp");

    auth_destroy(cl->cl_auth);
    cl->cl_auth = authsys_create_default();
}