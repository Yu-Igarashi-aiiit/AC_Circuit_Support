using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace sprashwindow1
{
    public partial class Form1 : Form
    {

        double R;//��RR
        double L;//�C���_�N�^���XL
        double C;//�R���_�N�^���XC
        double Z;//�C���s�[�_���XZ
        double F;//���g��F
        double E;//�d���lE
        double W;//�e���g����
        double degZ;//�C���s�[�_���XZ�̈ʑ�
        float real;//�C���s�[�_���XZ�̎���
        float imaginary;//�C���s�[�_���XZ�̋���
        double a;





        public Form1()
        {
            InitializeComponent();
        }


        //R�̏ꍇ
        private void trackBar2_Scroll(object sender, EventArgs e)
        {
            textBox1.Text = trackBar2.Value.ToString();  // �ʒu���擾
            R = (double)trackBar2.Value;
            L = (double)trackBar3.Value / (-1000);
            C = (double)trackBar4.Value / (-1000000);
            Z = Math.Sqrt(R * R + (W * L - 1 / (W * C)) * (W * L - 1 / (W * C)));
            F = Convert.ToDouble(textBox2.Text);
            E = Convert.ToDouble(textBox5.Text);
            W = 2 * Math.PI * F;
            degZ = Math.Atan((W * L - (1 / W * C)) / R);
            real = (float)((E*R) / (R * R + (W * L - 1 / (W * C)) * (W * L - 1 / (W * C))));
            imaginary = (float)((-E * (W * L - 1 / (W * C))) / (R * R + (W * L - 1 / (W * C)) * (W * L - 1 / (W * C))));

            //�`���Ƃ���Image�I�u�W�F�N�g���쐬����
            Bitmap canvas = new Bitmap(pictureBox3.Width, pictureBox3.Height); //cavas���r�b�g�}�b�v�`���ŏ������i�����s�N�`���{�b�N�X�̂��́j
            //Image�I�u�W�F�N�g��Graphics�I�u�W�F�N�g���쐬����
            pictureBox3.Image = canvas;//�s�N�`���{�b�N�X�ɂ�����悤�ɂ���B�����s�N�`���{�b�N�X�ɒ���
            Graphics g = Graphics.FromImage(pictureBox3.Image);//�s�N�`���{�b�N�X�ɏ����Ƃ����錾

            g.Clear(Color.White);//���F�ŏ�����
            Pen blackPen = new Pen(Color.Black, 1);
            Pen redPen = new Pen(Color.Red, 1);
            Pen border = new Pen(Color.Black, 1);
            blackPen.EndCap = LineCap.ArrowAnchor;//�I�_�ɖ�������
            redPen.EndCap = LineCap.ArrowAnchor;
            g.DrawLine(redPen, 180, 85, 180 + 10 * real, 85 + 10 * imaginary);
            g.DrawLine(blackPen, 180, 85, 180 + (float)E, 85);
            g.DrawLine(border, 180, 0, 180, 300);
            g.DrawLine(border, 0, 85, 500, 85);
            testChart();
        }


        //�k�̏ꍇ
        private void trackBar3_Scroll(object sender, EventArgs e)
        {
            // TrackBar �̃X���C�_�̈ʒu��\������
            textBox3.Text = trackBar3.Value.ToString();  // �ʒu���擾
            R = (double)trackBar2.Value;
            L = (double)trackBar3.Value / (-1000);
            C = (double)trackBar4.Value / (-1000000);
            Z = Math.Sqrt(R * R + (W * L - 1 / (W * C)) * (W * L - 1 / (W * C)));
            F = Convert.ToDouble(textBox2.Text);
            E = Convert.ToDouble(textBox5.Text);
            W = 2 * Math.PI * F;
            degZ = Math.Atan((W * L - (1 / W * C)) / R);
            real = (float)((E*R) / (R * R + (W * L - 1 / (W * C)) * (W * L - 1 / (W * C))));
            imaginary = (float)((-E * (W * L - 1 / (W * C))) / (R * R + (W * L - 1 / (W * C)) * (W * L - 1 / (W * C))));



            //�`���Ƃ���Image�I�u�W�F�N�g���쐬����
            Bitmap canvas = new Bitmap(pictureBox3.Width, pictureBox3.Height); //cavas���r�b�g�}�b�v�`���ŏ������i�����s�N�`���{�b�N�X�̂��́j
            //Image�I�u�W�F�N�g��Graphics�I�u�W�F�N�g���쐬����
            pictureBox3.Image = canvas;//�s�N�`���{�b�N�X�ɂ�����悤�ɂ���B�����s�N�`���{�b�N�X�ɒ���
            Graphics g = Graphics.FromImage(pictureBox3.Image);//�s�N�`���{�b�N�X�ɏ����Ƃ����錾

            g.Clear(Color.White);//���F�ŏ�����

            //Pen�I�u�W�F�N�g�̍쐬(��10�̍��F)
            Pen blackPen = new Pen(Color.Black, 1);
            Pen redPen = new Pen(Color.Red, 1);

            //�I�_�ɖ�������
            blackPen.EndCap = LineCap.ArrowAnchor;
            redPen.EndCap = LineCap.ArrowAnchor;
            //����`��
            g.DrawLine(redPen, 180, 85, 180 + 10 * real, 85 + 10 * imaginary);
            g.DrawLine(blackPen, 180, 85, 180 + (float)E, 85);

            Pen border = new Pen(Color.Black, 1);
            //����`��
            g.DrawLine(border, 180, 0, 180, 300);
            //����`��
            g.DrawLine(border, 0, 85, 500, 85);
            testChart();
        }



        //�b�̏ꍇ
        private void trackBar4_Scroll(object sender, EventArgs e)
        {
            // TrackBar �̃X���C�_�̈ʒu��\������

            textBox4.Text = trackBar4.Value.ToString();
            R = (double)trackBar2.Value;
            L = (double)trackBar3.Value / (-1000);
            C = (double)trackBar4.Value / (-1000000);
            Z = Math.Sqrt(R * R + (W * L - 1 / (W * C)) * (W * L - 1 / (W * C)));
            F = Convert.ToDouble(textBox2.Text);
            E = Convert.ToDouble(textBox5.Text);
            W = 2 * Math.PI * F;

            degZ = Math.Atan((W * L - (1 / W * C)) / R);
            real = (float)((E*R) / (R * R + (W * L - 1 / (W * C)) * (W * L - 1 / (W * C))));
            imaginary = (float)((-E * (W * L - 1 / (W * C))) / (R * R + (W * L - 1 / (W * C)) * (W * L - 1 / (W * C))));
            //real = (float)R;
            //imaginary = (float)(W * L - 1 / (W * C));



            //�`���Ƃ���Image�I�u�W�F�N�g���쐬����
            Bitmap canvas = new Bitmap(pictureBox3.Width, pictureBox3.Height); //cavas���r�b�g�}�b�v�`���ŏ������i�����s�N�`���{�b�N�X�̂��́j
            //Image�I�u�W�F�N�g��Graphics�I�u�W�F�N�g���쐬����
            pictureBox3.Image = canvas;//�s�N�`���{�b�N�X�ɂ�����悤�ɂ���B�����s�N�`���{�b�N�X�ɒ���
            Graphics g = Graphics.FromImage(pictureBox3.Image);//�s�N�`���{�b�N�X�ɏ����Ƃ����錾

            g.Clear(Color.White);//���F�ŏ�����

            //Pen�I�u�W�F�N�g�̍쐬(��10�̍��F)
            Pen blackPen = new Pen(Color.Black, 1);
            Pen redPen = new Pen(Color.Red, 1);

            //�I�_�ɖ�������
            blackPen.EndCap = LineCap.ArrowAnchor;
            redPen.EndCap = LineCap.ArrowAnchor;
            //����`��
            g.DrawLine(redPen, 180, 85, 180 + 10*real, 85 + 10*imaginary);
            g.DrawLine(blackPen, 180, 85, 180 + (float)E, 85);

            Pen border = new Pen(Color.Black, 1);
            //����`��
            g.DrawLine(border, 180, 0, 180, 300);
            //����`��
            g.DrawLine(border, 0, 85, 500, 85);
            testChart();

        }

        public void testChart()   //����Ŋ֐���������B��̂悤�ɐ錾���Ă��΂��̖߂�l�Ȃ��֐��𔭓��ł���B
        {
            R = (double)trackBar2.Value;
            L = (double)trackBar3.Value / (-1000);
            C = (double)trackBar4.Value / (-1000000);
            Z = Math.Sqrt(R * R + (W * L - 1 / (W * C)) * (W * L - 1 / (W * C)));
            F = Convert.ToDouble(textBox2.Text);
            E = Convert.ToDouble(textBox5.Text);
            W = 2 * Math.PI * F;
            degZ = Math.Atan((W * L - 1 / (W * C)) / R);

            // 1.Series�̒ǉ�
            chart1.Series.Clear();
            chart1.Series.Add("I");
            chart1.Series.Add("E");

            // 2.�O���t�̃^�C�v�̐ݒ�
            chart1.Series["I"].ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
            chart1.Series["E"].ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;

            // 3.���W�̓���
            for (double theta = 0; theta <= 2 * Math.PI; theta += Math.PI / 360)�@�@�@�@�@
            {
                chart1.Series["I"].Points.AddXY(theta, Math.Sqrt(2)*(E / Z) * Math.Sin(theta + degZ));//E/Z�̐�Βl��sin�Ɋ|������傫�����ς��
                chart1.Series["E"].Points.AddXY(theta, Math.Sqrt(2) * E/10 * Math.Sin(theta));
            }

        }

        private void ���b�����HToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form3 newForm = new Form3();
            newForm.ShowDialog();
        }

        private void ���k�����HToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form4 newForm = new Form4();
            newForm.ShowDialog();
        }

        private void ���k�b�����HToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form1 newForm = new Form1();
            newForm.ShowDialog();
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }
    }
}
