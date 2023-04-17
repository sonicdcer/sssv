#include <ultra64.h>
#include "common.h"

// tbd
u8 func_80322A58_734108(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, Animal **animal, Animal *arg6, u8 arg7);


// try_pickup_animal?
Animal *func_803213B0_732A60(void) {
    Animal *a = D_803D5530->unk6C;

    if ((a == NULL) &&
        (func_80322A58_734108(D_803D5530->xPos.h, D_803D5530->zPos.h, (s16) (D_803D5530->yPos.h - 0x10), 0x10, 0, &a, D_803D5530, 0)) &&
        (!(a->unk16C->unk82.unk2) || (a->unk366 != 5) || ((a->unk160 == 1) && (D_803D5530->unk160 == 2)))) {
        a = NULL;
    }

    if (a != NULL) {
        if ((a->unk16C->unk82.unk1 == 0) && (a->unk4C.unk27)) {
            if ((D_803D5524->unkC0 >= (s32) a->unk44) &&
                (((a->unk16C->unk82.unk2 == 0) && ((a->state == 0) || (a->state == 1))) || ((a->unk16C->unk82.unk2 != 0) && (a->unk366 == 5))) &&
                (a->unk4A == 0) && ((a->unk16C->unk82.unk2 == 0) || (a->unk44 < 100))) {
                D_803D552C->unk324 = a->state;
                D_803D552C->unk320 = a;
                a->state = 0x1FU;
                a->unk4C.unk25 = 1;
                play_sound_effect_at_location(SFX_UNKNOWN_40, 0x5000, 0, D_803D5530->xPos.h, D_803D5530->zPos.h, D_803D5530->yPos.h, 1.5f);
                if ((a->unk16C->unk82.unk2) == 0) {
                    if (a->unk163 & 8) {
                        a->unk163 |= 32;
                    }
                    a->unk163 |= 8;
                }
                return a;
            }
        }
    }
    return NULL;
}

Animal *func_803215DC_732C8C(s16 arg0, s16 arg1) {
    s32 pad[2];

    s16 temp_a2;
    s16 temp_v0;

    s16 temp_s1;
    s16 temp_s2;
    s16 temp_s3;
    s16 temp_s4;

    s16 temp_t1;
    s16 temp_t2;
    Animal *a;

    struct065 *temp_v1;


    temp_a2 = D_803D5530->xPos.h;
    temp_a2 += ((((s16) D_80152C78[D_803D552C->unk302 & 0xFF] >> 7) * arg0) >> 8);
    temp_v0 = D_803D5530->zPos.h;
    temp_v0 += ((((s16) D_80152C78[(D_803D552C->unk302 + 64) & 0xFF] >> 7) * arg0) >> 8);

    temp_s1 = temp_a2 - arg1; // x min
    temp_s2 = temp_v0 - arg1; // z min
    temp_s3 = temp_a2 + arg1; // x max
    temp_s4 = temp_v0 + arg1; // z max

    temp_t1 = D_803D5530->yPos.h - 64;     // y min
    temp_t2 = D_803D5530->yPos.h + 64 + D_803D5524->unkBA; // y max

    for (temp_v1 = D_803DA110[(s16) ((s16)(temp_a2 >> 0xA) + ((s16)(temp_v0 >> 0xA) * 5))].next; temp_v1 != NULL; temp_v1 = temp_v1->next) {
        a = temp_v1->animal;
        if ((a->xPos.h >= temp_s1) && (temp_s3 >= a->xPos.h)) {
            if ((a->zPos.h >= temp_s2) && (temp_s4 >= a->zPos.h)) {
                if ((a->yPos.h >= temp_t1) && (temp_t2 >= a->yPos.h)) {
                    if ((D_803D5524->unk9C == ELEPHANT) && (a->unk16C->objectType != 2)) {
                        return NULL;
                    }
                }
            }
        }
        if ((a != D_803D5530) && (a != D_803D5530->unk6C)) {
            if ((a->xPos.h >= temp_s1) && (temp_s3 >= a->xPos.h)) {
                if ((a->zPos.h >= temp_s2) && (temp_s4 >= a->zPos.h) && (a->unk16C->unk82.unk1 == 0) && (a->unk4C.unk27)) {
                    if ((a->yPos.h >= temp_t1) && (temp_t2 >= a->yPos.h)) {
                        if ((D_803D5524->unkC0 >= a->unk44) && (a->unk40 <= 3072) && ((a->state == 0) || (a->state == 1)) && (a->unk4A == 0)) {
                            D_803D552C->unk324 = a->state;
                            D_803D552C->unk320 = a;
                            a->state = 30;
                            a->unk4C.unk25 = 1;
                            return a;
                        }
                    }
                }
            }
        }
    }

    return NULL;
}

Animal *func_803218D8_732F88(Animal *arg0) {
    if (arg0 != NULL) {
        D_803D552C->unk324 = arg0->state;
        D_803D552C->unk320 = arg0;
        arg0->state = 30;
        arg0->unk4C.unk25 = 1;
        return arg0;
    }
    return NULL;
}

void func_80321920_732FD0(Animal *arg0, s16 arg1, s16 arg2) {
    if (arg0 != NULL) {
        arg0->xVelocity.h = D_803D5530->xVelocity.h + (((D_80152C78[D_803D552C->unk302 & 0xFF] >> 7) * arg1) >> 8);
        arg0->zVelocity.h = D_803D5530->zVelocity.h + (((D_80152C78[(D_803D552C->unk302 + 64) & 0xFF] >> 7) * arg1) >> 8);
        arg0->yVelocity.h = (D_803D5530->yVelocity.h + arg2) - 1;
        arg0->unk4C.unk25 = 1;
        arg0->unk160 = D_803D5530->unk160;
        if (arg0->unk160 != 0) {
            if (((arg0->unk160 == 1) || (arg0->unk160 == 2)) && (D_803C0740[arg0->xPos.h >> 6][arg0->zPos.h >> 6].unk3 == 0)) {
                arg0->unk160 = 0U;
            }
        } else {
            if (D_803C0740[arg0->xPos.h >> 6][arg0->zPos.h >> 6].unk3 != 0) {
                if ((func_80310F58_722608(arg0->xPos.h, arg0->zPos.h) >> 0x10) < arg0->yPos.h) {
                    arg0->unk160 = 2U;
                } else {
                    arg0->unk160 = 1U;
                }
            }
        }

        arg0->state = D_803D552C->unk324;
        D_803D552C->unk320 = 0;

        if (arg0->yRotation < 45) {
            arg0->yRotation = 0;
        } else if (arg0->yRotation < 135) {
            arg0->yRotation = 90;
        } else if (arg0->yRotation < 225) {
            arg0->yRotation = 180;
        } else if (arg0->yRotation < 315) {
            arg0->yRotation = 270;
        } else {
            arg0->yRotation = 0;
        }
        if (arg0->unk16C->unk82.unk2 == 0) {
            if ((arg0->unk163 & 0x20) == 0) {
                // remove flags
                arg0->unk163 &= -(8 | 1);
            }
        }
    }
}

void func_80321B70_733220(s16 arg0, s16 arg1, s16 arg2) {
    s32 temp_t0;

    Animal *a = D_803D552C->unk320;
    if (a != 0) {
        a->xPos.h = (((D_80152C78[D_803D552C->unk302 & 0xFF] >> 7) * arg1) >> 8) + (D_803D5530->xPos.h + (((D_80152C78[(D_803D552C->unk302 + 64) & 0xFF] >> 7) * arg0) >> 8));
        a->zPos.h = D_803D5530->zPos.h + (((D_80152C78[(D_803D552C->unk302 + 64) & 0xFF] >> 7) * arg1) >> 8) - (((D_80152C78[D_803D552C->unk302 & 0xFF] >> 7) * arg0) >> 8);
        a->yPos.h = D_803D5530->yPos.h + arg2;
        a->unk160 = D_803D5530->unk160;
        a->xVelocity.w = D_803D5530->xVelocity.w;
        a->zVelocity.w = D_803D5530->zVelocity.w;
        a->yVelocity.w = D_803D5530->yVelocity.w;

        temp_t0 = D_803D552C->unk302 - D_803D552C->unk304;
        if (a->unk16C->unk82.unk2 != 0) {
            a->yRotation = ((a->yRotation + temp_t0) & 0xFF);
            a->unk302 = a->yRotation;
        } else {
            temp_t0 = (temp_t0 * 360) / 256;
            a->yRotation += temp_t0;
            while (a->yRotation < 0) {
                a->yRotation += 360;
            }
            while (a->yRotation >= 360) {
                a->yRotation -= 360;
            }
        }
    }
}

void func_80321D74_733424(s16 arg0, s16 arg1) {
    Animal *a = D_803D552C->unk320;
    if (a != NULL) {
        a->xPos.h = D_803D5530->xPos.h + (((D_80152C78[D_803D552C->unk302 & 0xFF] >> 7) * arg0) >> 8);
        a->zPos.h = D_803D5530->zPos.h + (((D_80152C78[(D_803D552C->unk302 + 64) & 0xFF] >> 7) * arg0) >> 8);
        a->yPos.h = D_803D5530->yPos.h + arg1;
        a->xVelocity.w = D_803D5530->xVelocity.w;
        a->zVelocity.w = D_803D5530->zVelocity.w;
        a->yVelocity.w = D_803D5530->yVelocity.w;
    }
}

void func_80321E60_733510(u8 id, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7) {
    s32 sp3C;
    s32 sp38;
    s32 sp34;

    s16 xpos;
    s16 zpos;

    struct071 *obj;

    s16 _id = id & 0xFFFF;

    xpos = (((arg1 * (D_80152C78[D_803D552C->unk302 & 0xFF] >> 7)) + ((D_80152C78[(D_803D552C->unk302 + 0x40) & 0xFF] >> 7) * arg2)) >> 8);
    zpos = (((arg1 * (D_80152C78[(D_803D552C->unk302 + 0x40) & 0xFF] >> 7)) - ((D_80152C78[D_803D552C->unk302 & 0xFF] >> 7) * arg2)) >> 8);

    sp38 = ((D_80152C78[(arg5 + 0x40) & 0xFF] >> 7) * arg4) * (D_80152C78[D_803D552C->unk302 & 0xFF] >> 7);
    sp34 = ((D_80152C78[(arg5 + 0x40) & 0xFF] >> 7) * arg4) * (D_80152C78[(D_803D552C->unk302 + 0x40) & 0xFF] >> 7);
    sp3C = (((D_80152C78[arg5 & 0xFF] >> 7) * arg4) << 8);


    obj = func_802C9564_6DAC14(
        _id,
        D_803D5530->xPos.h + xpos,
        D_803D5530->zPos.h + zpos,
        D_803D5530->yPos.h + arg3,
        D_803D5530->xVelocity.w + sp38,
        D_803D5530->zVelocity.w + sp34,
        D_803D5530->yVelocity.w + sp3C,
        0,
        0,
        0);

    if (obj != NULL) {
        D_803D5530->xVelocity.w -= sp38 >> arg6;
        D_803D5530->zVelocity.w -= sp34 >> arg6;
        obj->unk168 = D_803D5530;
        obj->unk15C = 0xF;
        if (arg7 != 0) {
            obj->unk15E = arg7;
        }
    }
}

void func_80322064_733714(u8 id, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8) {
    s32 sp3C;
    s32 sp38;
    s32 sp34;

    s16 xpos;
    s16 zpos;
    struct071 *obj;

    s16 _id = id & 0xFFFF;

    xpos = ((arg1 * (D_80152C78[arg5 & 0xFF] >> 7)) + ((D_80152C78[(arg5 + 0x40) & 0xFF] >> 7) * arg2)) >> 8;
    zpos = ((arg1 * (D_80152C78[(arg5 + 0x40) & 0xFF] >> 7)) - ((D_80152C78[arg5 & 0xFF] >> 7) * arg2)) >> 8;

    sp38 = ((D_80152C78[(arg6 + 0x40) & 0xFF] >> 7) * arg4) * (D_80152C78[arg5 & 0xFF] >> 7);
    sp34 = ((D_80152C78[(arg6 + 0x40) & 0xFF] >> 7) * arg4) * (D_80152C78[(arg5 + 0x40) & 0xFF] >> 7);
    sp3C = ((D_80152C78[arg6 & 0xFF] >> 7) * arg4) << 8;

    obj = func_802C9564_6DAC14(
        _id,
        D_803D5530->xPos.h + xpos,
        D_803D5530->zPos.h + zpos,
        D_803D5530->yPos.h + arg3,
        D_803D5530->xVelocity.w + sp38,
        D_803D5530->zVelocity.w + sp34,
        D_803D5530->yVelocity.w + sp3C,
        0,
        0,
        0);

    if (obj != NULL) {
        D_803D5530->xVelocity.w -= sp38 >> arg7;
        D_803D5530->zVelocity.w -= sp34 >> arg7;
        obj->unk168 = D_803D5530;
        obj->unk15C = 0xF;
        if (arg8 != 0) {
            obj->unk15E = arg8;
        }
    }
}

void func_8032225C_73390C(u8 id, s16 arg1, s16 arg2, s16 arg3, s32 arg4, s32 arg5, s32 arg6, s16 arg7, s16 arg8) {
    s16 xpos;
    s16 zpos;

    short _id;

    struct071 *obj;

    _id = id & 0xffff;

    xpos = (((arg1 * (D_80152C78[D_803D552C->unk302 & 0xFF] >> 7)) + ((D_80152C78[(D_803D552C->unk302 + 64) & 0xFF] >> 7) * arg2)) >> 8);
    zpos = (((arg1 * (D_80152C78[(D_803D552C->unk302 + 64) & 0xFF] >> 7)) - ((D_80152C78[D_803D552C->unk302 & 0xFF] >> 7) * arg2)) >> 8);

    obj = func_802C9564_6DAC14(
        _id,
        D_803D5530->xPos.h + xpos,
        D_803D5530->zPos.h + zpos,
        D_803D5530->yPos.h + arg3,
        D_803D5530->xVelocity.w + arg4,
        D_803D5530->zVelocity.w + arg5,
        D_803D5530->yVelocity.w + arg6,
        0,
        0,
        0);

    if (obj != NULL) {
        D_803D5530->xVelocity.w -= arg4 >> arg7;
        D_803D5530->zVelocity.w -= arg5 >> arg7;
        obj->unk168 = D_803D5530;
        if (arg8 != 0) {
            obj->unk15E = arg8;
        }
    }
}

void apply_recoil(s16 arg0) {
    s32 temp_t2 = D_80152C78[(u8)D_803D552C->unk302] >> 7;
    s32 temp_t7 = D_80152C78[(u8)(D_803D552C->unk302 + 64)] >> 7;

    if (arg0 < 0) {
        D_803D5530->xVelocity.w += temp_t2 << (8 - arg0);
        D_803D5530->zVelocity.w += temp_t7 << (8 - arg0);
    } else {
        D_803D5530->xVelocity.w -= temp_t2 << (arg0 + 8);
        D_803D5530->zVelocity.w -= temp_t7 << (arg0 + 8);
    }
}

#ifdef NON_MATCHING
// stack + regalloc
s16 func_803224C4_733B74(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, u8 arg7) {
    s16 var_t3;
    s16 var_t4;
    s16 var_t5;
    s16 var_t0;

    s32 pad[2];
    struct065 *var_ra;
    struct043 *var_a1;

    Animal *animal; // sp34
    s16 ret;

    ret = 0;

    var_t3 = (D_803D5530->xPos.h + (((D_80152C78[D_803D552C->unk302 & 0xFF] >> 7) * arg1) >> 8) + (((D_80152C78[(D_803D552C->unk302 + 0x40) & 0xFF] >> 7) * arg2) >> 8));
    var_t4 = (D_803D5530->zPos.h + (((D_80152C78[(D_803D552C->unk302 + 0x40) & 0xFF] >> 7) * arg1) >> 8)) - (((D_80152C78[D_803D552C->unk302 & 0xFF] >> 7) * arg2) >> 8);
    var_t5 = D_803D5530->yPos.h + arg0;

    for (var_ra = D_803DA110[(s16) ((s16)(var_t3 >> 0xA) + ((s16)(var_t4 >> 0xA) * 5))].next; var_ra != NULL; var_ra = var_ra->next) {
        animal = var_ra->animal;
        if ((animal != D_803D5530) && (animal != D_803D5530->unk6C) && (((animal->unk16C->unk82.unk2 != 0) && ((animal == D_801D9ED8.animals[gCurrentAnimalIndex].animal) || (D_803D5538 != 0) || (animal->unk16C->unk9C != D_803D5524->unk9C))) || ((animal->unk16C->unk82.unk2 == 0) && (animal->unk16C->objectType != 0x40)))) {
            for (var_a1 = animal->unkC4; var_a1->unkC != 0; var_a1++) {
                if (ABS((animal->xPos.h + var_a1->unk0.h) - var_t3) < (var_a1->unkC + arg3) &&
                    ABS((animal->zPos.h + var_a1->unk4.h) - var_t4) < (var_a1->unkC + arg3) &&
                    ABS((animal->yPos.h + var_a1->unk8.h) - var_t5) < (var_a1->unkC + arg3)) {

                    var_t0 = 0;
                    if (arg7 != 0) {
                        animal->unk57 = arg7;
                    }
                    if (D_803D5530->unk44 < animal->unk44) {
                        var_t0 = 1;
                    }
                    if ((D_803D5530->unk44 * 2) < animal->unk44) {
                        var_t0++;
                    }
                    if ((D_803D5530->unk44 * 3) < animal->unk44) {
                        var_t0++;
                    }

                    if ((animal->unk4C.unk27 == 0) || (D_803D5524->unk9C == HARD_MOUSE) || ((animal->unk16C->unk82.unk2 == 0) && (D_803D5530->unk44 < animal->unk44))) {
                        var_t0 = 8;
                    }

                    if (animal->unk16C->unk82.unk2 != 0) {
                        func_802B356C_6C4C1C(animal, arg4, D_803D5524->unkE6, 1);
                        ret = 2;
                        if (D_803D5538 != 0) {
                            animal->unk2EB++;
                        }
                    } else if (animal->unk4C.unk26 == 0) {
                        if (animal->unk4A == 0) {
                            animal->health = MAX(0, animal->health - MAX(1, arg4 >> var_t0));
                            if (ret == 0) {
                                ret = 1;
                            }
                        }
                    }

                    func_802FD674_70ED24(D_803D5530, animal);
                    if (var_t0 < 6) {
                        animal->xVelocity.h += (D_80152C78[D_803D552C->unk302 & 0xFF] >> 7) >> (var_t0 + 6);
                        animal->zVelocity.h += (D_80152C78[(D_803D552C->unk302 + 0x40) & 0xFF] >> 7) >> (var_t0 + 6);

                        animal->unk65 = MIN(100, animal->unk65 + (20 >> var_t0));
                    }

                    animal->unk4C.unk25 = 1;

                    if ((animal->unk16C->unk82.unk2 != 0) && ((animal->unk366 == 1) || (animal->unk366 == 3) || (animal->unk366 == 4))) {
                        animal->unk348 = MAX(animal->unk348, arg6);
                        animal->unk34A = MAX(animal->unk34A, arg5);
                    }
                    break;
                }
            }
        }
    }
    return ret;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_732A60/func_803224C4_733B74.s")
#endif

u8 func_80322A58_734108(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 damage, Animal **arg5, Animal *arg6, u8 arg7) {
    s32 pad[2];
    struct065 *temp_t8;
    struct043 *phi_s2; // ?
    u8 pad2[3];
    u8 ret;
    s16 phi_s1;
    Animal *a;

    ret = 0;

    for (temp_t8 = D_803DA110[(s16)((s16)(arg0 >> 0xA) + ((s16)(arg1 >> 0xA) * 5))].next; temp_t8 != NULL; temp_t8 = temp_t8->next) {
        a = temp_t8->animal;
        if ((a != D_803D5530) && (a != arg6) && (a->unk16C->objectType != 64)) {
            for (phi_s2 = a->unkC4; phi_s2->unkC != 0; phi_s2++) {
                if ((ABS((a->xPos.h + phi_s2->unk0.h) - arg0) < phi_s2->unkC + arg3) &&
                    (ABS((a->zPos.h + phi_s2->unk4.h) - arg1) < phi_s2->unkC + arg3) &&
                    (ABS((a->yPos.h + phi_s2->unk8.h) - arg2) < phi_s2->unkC + arg3)) {
                    ret = 1;
                    if (arg7 != 0) {
                        a->unk57 = arg7;
                    }
                    if (arg5 != NULL) {
                        *arg5 = a;
                    }
                    if (a->unk16C->unk82.unk2) {
                        func_802FD674_70ED24(D_803D5530, a);
                        phi_s1 = 0;
                        if (D_803D5530->unk44 < a->unk44) {
                            phi_s1 = 1;
                        }
                        if ((D_803D5530->unk44 * 2) < a->unk44) {
                            phi_s1 += 1;
                        }
                        if ((D_803D5530->unk44 * 3) < a->unk44) {
                            phi_s1 += 1;
                        }
                        // apply fall damage between animals?
                        func_802B356C_6C4C1C(a, damage, D_803D5524->unkE6, 1);
                        if (D_803D5538 != 0) {
                            a->unk2EB += 1;
                        }
                        a->unk65 = MIN(100, a->unk65 + (0x14 >> phi_s1));
                        a->unk4C.unk25 = 1;
                    } else if ((a->unk4A == 0) && (a->unk4C.unk26 == 0)) {
                        a->health = MAX(0, a->health);
                    }
                }
            }
        }
    }
    return ret;
}

s32 func_80322D68_734418(s16 xPos0, s16 zPos0, s16 yPos0, s16 xPos1, s16 zPos1, s16 yPos1, s16 *arg6, s16 *arg7, s16 *arg8, s16 arg9, s16 damage, u8 argB, u8 argC) {

    s32 pad;
    s32 ret;

    s32 var_v1;
    s32 var_t0;
    s32 var_t1;

    s16 i;
    s16 distance;

    s32 var_s5;
    s32 var_s4;
    s32 var_s3;

    Animal *sp68;

    ret = 0;

    var_v1 = xPos1 - xPos0;
    var_t0 = zPos1 - zPos0;
    var_t1 = yPos1 - yPos0;

    distance = sqrtf(SQ((f32)var_v1) + SQ((f32)var_t0) + SQ((f32)var_t1));
    distance = (distance / ((arg9 * 3) >> 1)) + 1;

    var_v1 = (var_v1 << 0x10) / (distance + 1);
    var_t0 = (var_t0 << 0x10) / (distance + 1);
    var_t1 = (var_t1 << 0x10) / (distance + 1);

    var_s3 = (xPos0 << 0x10) + (var_v1 >> 1);
    var_s4 = (zPos0 << 0x10) + (var_t0 >> 1);
    var_s5 = (yPos0 << 0x10) + (var_t1 >> 1);

    for (i = 0; i < distance; i++) {
        if (func_80322A58_734108(var_s3 >> 0x10, var_s4 >> 0x10, var_s5 >> 0x10, arg9, damage, &sp68, sp68, argC)) {
            *arg6 = var_s3 >> 0x10;
            *arg7 = var_s4 >> 0x10;
            *arg8 = var_s5 >> 0x10;
            if (sp68->unk16C->unk82.unk2) {
                ret = 2;
              } else {
                ret = 1;
            }

            // every animal except EVO?
            if (!argB) {
                break;
            }

        }
        var_s3 += var_v1;
        var_s4 += var_t0;
        var_s5 += var_t1;
    }
    return ret;
}

Animal *func_80323040_7346F0(void) {
    s16 temp_fp;
    s16 x_dist;
    s16 z_dist;
    s16 candidate;
    s16 temp_s7;
    s16 temp_v0;
    s16 y_dist;

    Animal *temp_s3;
    struct065 *temp_s4;

    s16 phi_a0;
    s16 phi_a2;
    s16 phi_a1;
    s16 phi_v0;
    s16 phi_v1;
    s16 best;
    f32 phi_f2;
    Animal *res;

    s16 x;
    s16 y;

    x = (D_803D5530->xPos.h >> 0xA);
    y = (D_803D5530->zPos.h >> 0xA);

    res = NULL;
    best = 320;

    temp_s7 = (D_80152C78[D_803D552C->unk302 & 0xFF]) >> 9;
    temp_fp = (D_80152C78[(D_803D552C->unk302 + 64) & 0xFF]) >> 9;

    for (temp_s4 = D_803DA110[(s16) (x + (y * 5))].next; temp_s4 != NULL; temp_s4 = temp_s4->next) {
        temp_s3 = temp_s4->animal;
        if ((temp_s3 != D_803D5530) && (((temp_s3->unk16C->unk82.unk2) && (temp_s3->unk366 != 5) &&
                                        ((temp_s3->unk16C->objectType != OB_TYPE_ANIMAL_OFFSET+EVO_MICROCHIP)) &&
                                        (temp_s3->unk16C->objectType != OB_TYPE_ANIMAL_OFFSET+EVO_TRANSFER) &&
                                        (temp_s3->unk16C->objectType != OB_TYPE_ANIMAL_OFFSET+EVO)) || (temp_s3->unk16C->objectType == 145))) {
            x_dist = D_803D5530->xPos.h - temp_s3->xPos.h;
            z_dist = D_803D5530->zPos.h - temp_s3->zPos.h;
            y_dist = D_803D5530->yPos.h - temp_s3->yPos.h;

            phi_a2 = ABS(x_dist);
            phi_a0 = ABS(z_dist);
            phi_a1 = ABS(y_dist);

            candidate = (MAX(MAX(phi_a2, phi_a0), phi_a1) >> 1) + (phi_a2 >> 1) + (phi_a0 >> 1) + (phi_a1 >> 1);
            if (candidate < best) {
                phi_f2 = MAX(1.0, sqrtf((x_dist * x_dist) + (z_dist * z_dist)));
                if ((s16) (-((x_dist * temp_s7) + (z_dist * temp_fp)) / phi_f2) > 0) {
                    best = candidate;
                    res = temp_s3;
                }
            }
        }

    }
    return res;
}

// miles away
#if 0
s32 func_803233A0_734A50(s16 x0, s16 y0, s16 z0, s16 x1, s16 y1, s16 z1) {

    s16 temp_v1;

    struct065 *temp_a1;
    Animal *a;
    s32 phi_a2;
    s32 phi_a3;
    s32 phi_t0;
    s16 i;

    s32 tmp1 = (x0 - x1);
    s32 tmp2 = (y0 - y1);
    s32 tmp3 = (z0 - z1);

    f32 tmpf1 = tmp1;
    f32 tmpf2 = tmp2;
    f32 tmpf3 = tmp3;

    temp_v1 = ((s16) sqrtf((tmpf1 * tmpf1) + (tmpf2 * tmpf2) + (tmpf3 * tmpf3)) / 10) + 1;

    phi_a2 = (x1 << 0x10) + ((tmp1 << 0x10) / (temp_v1 + 1) >> 1);
    phi_a3 = (y1 << 0x10) + ((tmp2 << 0x10) / (temp_v1 + 1) >> 1);
    phi_t0 = (z1 << 0x10) + ((tmp3 << 0x10) / (temp_v1 + 1) >> 1);

    // i = 0;
    for (i = 0; i < temp_v1; i++) {
        for (temp_a1 = D_803DA110[(s16) ((s16)(phi_a2 >> 0x1A) + ((s16) (phi_a3 >> 0x1A) * 5))].next; temp_a1 != NULL; temp_a1 = temp_a1->next) {
            a = temp_a1->animal;
            if (a->unk16C->objectType == 91) {
                if ((a->yPos.h < (phi_t0 >> 0x10)) && ((phi_t0 >> 0x10) < (a->yPos.h + a->unk42))) {
                    if (a->unk30 >= ABS((phi_a2 >> 0x10) - a->xPos.h)) {
                        if (a->unk32 >= ABS((phi_a3 >> 0x10) - a->zPos.h)) {
                            return 1;
                        }
                    }
                }
                if (1) { } if (1) { } if (1) { } if (1) { } if (1) { }
            }
        }

        phi_a2 += (tmp1 << 0x10) / (temp_v1 + 1);
        phi_a3 += (tmp2 << 0x10) / (temp_v1 + 1);
        phi_t0 += (tmp3 << 0x10) / (temp_v1 + 1);
    }

    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlay2_732A60/func_803233A0_734A50.s")
#endif
