
void R() {
    for (int i = 1; i < 4; i++) {
        char tmp;
        tmp = cube[0][i][3];
        cube[0][i][3] = cube[5][i][3];
        cube[5][i][3] = cube[1][4-i][1];
        cube[1][4-i][1] = cube[4][i][3];
        cube[4][i][3] = tmp;
    }
    char tmp_2[4][4];
    for (int i = 1; i < 4; i++) {
        for (int j = 1; j < 4; j++) {
            tmp_2[i][j] = cube[3][4-j][i];
        }
    }
    for (int i = 1; i < 4; i++) {
        for (int j = 1; j < 4; j++) {
            cube[3][i][j] = tmp_2[i][j];
        }
    }
}
void Ri() {
    for (int i = 0; i < 3; i++) {
        R();
    }
}
void L() {
    for (int i = 1; i < 4; i++) {
        char tmp;
        tmp = cube[0][i][1];
        cube[0][i][1] = cube[4][i][1];
        cube[4][i][1] = cube[1][4-i][3];
        cube[1][4-i][3] = cube[5][i][1];
        cube[5][i][1] = tmp;
    }
    char tmp_2[4][4];
    for (int i = 1; i < 4; i++) {
        for (int j = 1; j < 4; j++) {
            tmp_2[i][j] = cube[2][4-j][i];
        }
    }
    for (int i = 1; i < 4; i++) {
        for (int j = 1; j < 4; j++) {
            cube[2][i][j] = tmp_2[i][j];
        }
    }
}
void Li() {
    for (int i = 0; i < 3; i++) {
        L();
    }
}
void U() {
    for (int i = 1; i < 4; i++) {
        char tmp;
        tmp = cube[0][1][i];
        cube[0][1][i] = cube[3][1][i];
        cube[3][1][i] = cube[1][1][i];
        cube[1][1][i] = cube[2][1][i];
        cube[2][1][i] = tmp;
    }
    char tmp_2[4][4];
    for (int i = 1; i < 4; i++) {
        for (int j = 1; j < 4; j++) {
            tmp_2[i][j] = cube[4][4-j][i];
        }
    }
    for (int i = 1; i < 4; i++) {
        for (int j = 1; j < 4; j++) {
            cube[4][i][j] = tmp_2[i][j];
        }
    }
}
void Ui() {
    for (int i = 0; i < 3; i++) {
        U();
    }
}
void D() {
    for (int i = 1; i < 4; i++) {
        char tmp;
        tmp = cube[0][3][i];
        cube[0][3][i] = cube[2][3][i];
        cube[2][3][i] = cube[1][3][i];
        cube[1][3][i] = cube[3][3][i];
        cube[3][3][i] = tmp;
    }
    char tmp_2[4][4];
    for (int i = 1; i < 4; i++) {
        for (int j = 1; j < 4; j++) {
            tmp_2[i][j] = cube[5][4-j][i];
        }
    }
    for (int i = 1; i < 4; i++) {
        for (int j = 1; j < 4; j++) {
            cube[5][i][j] = tmp_2[i][j];
        }
    }
}
void Di() {
    for (int i = 0; i < 3; i++) {//DÈý´Î
        D();
    }
}
void B() {
    for (int i = 1; i < 4; i++) {
        char tmp;
        tmp = cube[4][1][i];
        cube[4][1][i] = cube[3][i][3];
        cube[3][i][3] = cube[5][3][4-i];
        cube[5][3][4-i] = cube[2][4-i][1];
        cube[2][4-i][1] = tmp;
    }
    char tmp_2[4][4];
    for (int i = 1; i < 4; i++) {
        for (int j = 1; j < 4; j++) {
            tmp_2[i][j] = cube[1][4-j][i];
        }
    }
    for (int i = 1; i < 4; i++) {
        for (int j = 1; j < 4; j++) {
            cube[1][i][j] = tmp_2[i][j];
        }
    }
}
void Bi() {
    for (int i = 0; i < 3; i++) {
        B();
    }
}
void F() {
    for (int i = 1; i < 4; i++) {
        char tmp;
        tmp = cube[4][1][i];
        cube[4][3][i] = cube[2][4-i][3];
        cube[2][4-i][3] = cube[5][1][4-i];
        cube[5][1][4-i] = cube[3][i][1];
        cube[3][i][1] = tmp;
    }
    char tmp_2[4][4];
    for (int i = 1; i < 4; i++) {
        for (int j = 1; j < 4; j++) {
            tmp_2[i][j] = cube[0][4-j][i];
        }
    }
    for (int i = 1; i < 4; i++) {
        for (int j = 1; j < 4; j++) {
            cube[0][i][j] = tmp_2[i][j];
        }
    }
}
void Fi() {
    for (int i = 0; i < 3; i++) {
        F();
    }
}

